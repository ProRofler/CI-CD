#include "bulk_commands_handler.h"

#include <assert.h>

#include <algorithm>

#include "bulk_builder.h"
#include "bulk_commands_list.h"

#define cmd_list cmds_list::commands_list

bool bulk_commands_handler::command_is_valid(const std::string& input) const {
    if (std::find(begin(cmd_list), end(cmd_list), input) != end(cmd_list)) {
        return true;
    }
    return false;
}

void bulk_commands_handler::handle_input(const std::string& input) {
    if (!input.empty() && (input.at(0) == '{' || input.at(0) == '}')) {
        builder.get_runner_ptr()->switch_state(input.at(0));
    } else if (!input.empty() && (input == "help" || input == "exit")) {
        auto command = builder.get_command_builder_basic_ptr()->build_command(
            input, *builder.get_io_ptr());
        command->command_action();
    } else if (command_is_valid(input)) {
        send_to_runner(input);
    } else {
        builder.get_io_ptr()->print_mesage("Invalid command");
        builder.get_io_ptr()->input_command();
    }
}

void bulk_commands_handler::send_to_runner(const std::string& input) {
    builder.get_runner_ptr()->add_to_bulk(
        builder.get_command_builder_custom_ptr()->build_command(
            input, *builder.get_io_ptr()));
}