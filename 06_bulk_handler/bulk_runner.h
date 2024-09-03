#pragma once
#include <memory>
#include <vector>

class bulk_command;

class bulk_runner {
   private:
    std::vector<std::unique_ptr<bulk_command>> queue;

    const size_t static_size = 3;
    bool dynamic = false;

    void switch_state() { dynamic = !dynamic; }
    bool is_full() const;
    void run_queue();

   public:
    bulk_runner() = default;

    bool is_dynamic_state() const { return dynamic; }
    void add_to_bulk(std::unique_ptr<bulk_command> command);
};