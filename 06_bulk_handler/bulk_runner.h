#pragma once
#include <memory>
#include <vector>

class bulk_command;
class bulk_logger;
class bulk_threads;

class bulk_runner {
   private:
    std::vector<std::unique_ptr<bulk_command>> queue;
    bulk_logger& logger;
    bulk_threads& threads;

    const size_t static_size = 3;
    bool dynamic = false;

    bool is_full() const;
    void run_queue();

   public:
    bulk_runner() = delete;
    bulk_runner(bulk_logger& _logger, bulk_threads& _threads) : logger(_logger), threads(_threads) {}

    void switch_state(const char& input);
    bool is_queue_empty() { return queue.empty(); }
    void add_to_bulk(std::unique_ptr<bulk_command> command);
};