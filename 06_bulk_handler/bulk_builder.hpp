#pragma once

#include <memory>

// forward declarations
class bulk_commands_handler;
class bulk_io;
class bulk_logger;
class bulk_state_machine;

class bulk_builder {
   private:
    std::shared_ptr<bulk_commands_handler> p_commands_handler = nullptr;
    std::unique_ptr<bulk_io> p_io = nullptr;
    std::unique_ptr<bulk_logger> p_logger = nullptr;
    std::unique_ptr<bulk_state_machine> p_state_machine = nullptr;

    // methods
    void create_system();

   public:
    bulk_builder() { create_system(); }

    // get
    std::shared_ptr<bulk_commands_handler> get_commands_handler() {
        return p_commands_handler;
    };
};