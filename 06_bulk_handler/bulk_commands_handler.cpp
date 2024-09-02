#include "bulk_commands_handler.h"

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
        builder.get_io_ptr()->print_mesage("Switching state...");
        builder.get_io_ptr()->input_command();
    } else if (!input.empty() && (input == "exit" || input == "exit")) {
        // make basic command
    } else if (command_is_valid(input)) {
        // build custom command
    } else {
        builder.get_io_ptr()->print_mesage("Invalid command");
        builder.get_io_ptr()->input_command();
    }
}

void bulk_commands_handler::command_pass(
    [[maybe_unused]] const std::string& input) const {
    // pass the command futher the chain
}