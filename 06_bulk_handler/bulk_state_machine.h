#pragma once
#include <memory>

class bulk_commands_handler;

class bulk_state_machine {
   private:
    bool dynamic = false;
    const std::shared_ptr<bulk_commands_handler> p_command_handler = nullptr;

   public:
    bulk_state_machine() = delete;
    bulk_state_machine(std::shared_ptr<bulk_commands_handler> p_com_handler)
        : p_command_handler(p_com_handler) {}

    bool is_dynamic_state() { return dynamic; }
    void switch_state();
};