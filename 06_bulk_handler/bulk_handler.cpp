#include "bulk_handler.hpp"

#include <algorithm>
#include <limits>

#include "commands.hpp"

void bulk_handler::start() {
    std::cout << "Enter command or type \"help\" to see the available options:"
              << std::endl;
    add_command();
}

void bulk_handler::run_block() {
    // run all commands
    std::cout << "Number of commands: " << commands_user.size()
              << "\nOhhh so much commands to run!!" << std::endl;
}

void bulk_handler::show_commands() {
    std::cout << "Available commands:\n";
    for (auto& c : cmds::cmds_list) {
        std::cout << "- " << c << std::endl;
    }
}

void bulk_handler::add_command() {
    std::string input;

    std::cin >> input;
    clear_io_buffer();

    // checking the command by user, refactor later
    if ((std::find(cmds::cmds_list.begin(), cmds::cmds_list.end(), input)) !=
        cmds::cmds_list.end()) {
        commands_user.push_back(input);
    } else {
        std::cout << "Invalid command" << std::endl;
    }

    // checking the dynamic or static block, refactor
    if (commands_user.size() == static_size && !use_dynamic_size) {
        run_block();
    } else {
        add_command();
    }
}

void bulk_handler::clear_io_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
