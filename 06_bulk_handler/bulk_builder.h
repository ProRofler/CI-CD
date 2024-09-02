#pragma once

#include <memory>

#include "bulk_command_builder.h"
#include "bulk_commands_handler.h"
#include "bulk_io.h"
#include "bulk_logger.h"
#include "bulk_state_machine.h"

// forward declarations
// class bulk_commands_handler;
// class bulk_io;
// class bulk_logger;
// class bulk_state_machine;

class bulk_builder {
   private:
    std::shared_ptr<bulk_commands_handler> p_commands_handler = nullptr;
    std::unique_ptr<bulk_io> p_io = nullptr;
    std::unique_ptr<bulk_logger> p_logger = nullptr;
    std::unique_ptr<bulk_state_machine> p_state_machine = nullptr;
    std::unique_ptr<bulk_command_builder_basic> p_command_builder_basic =
        nullptr;
    std::unique_ptr<bulk_command_builder_custom> p_command_builder_custom =
        nullptr;

    // methods
    void create_system();

   public:
    bulk_builder() { create_system(); }

    std::unique_ptr<bulk_io>& get_io_ptr() { return p_io; }
    std::unique_ptr<bulk_logger>& get_logger_ptr() { return p_logger; }
    std::unique_ptr<bulk_state_machine>& get_state_machine_ptr() {
        return p_state_machine;
    }
    std::unique_ptr<bulk_command_builder_basic>&
    get_command_builder_basic_ptr() {
        return p_command_builder_basic;
    }
    std::unique_ptr<bulk_command_builder_custom>&
    get_command_builder_custom_ptr() {
        return p_command_builder_custom;
    }
};