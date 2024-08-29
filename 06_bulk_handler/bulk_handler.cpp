#include "bulk_handler.hpp"

#include <algorithm>
#include <limits>

#define find_in_list \
    (std::find(cmds::cmds_list.begin(), cmds::cmds_list.end(), input))

#include "commands.hpp"

void bulk_handler::start() {
    std::cout << "Enter command or type \"help\" to see the available options:"
              << std::endl;
    while (run) {
        check_input(get_user_input());
    }
}

std::string bulk_handler::get_user_input() {
    std::string input;
    std::cin >> input;
    clear_io_buffer();

    return input;
}

void bulk_handler::show_commands() {
    std::cout << "Available commands:\n";
    for (auto& c : cmds::cmds_list) {
        std::cout << "- " << c << std::endl;
    }
}

void bulk_handler::run_block() {
    std::cout << "Number of commands: " << commands_user.size()
              << "\nOhhh so much commands to run!!" << std::endl;
}

void bulk_handler::clear_io_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void bulk_handler::check_input(const std::string& input) {
    if (find_in_list == cmds::cmds_list.end()) {
        std::cout << "Invalid command" << std::endl;
    } else if (input == "help") {
        show_commands();
    } else {
        commands_user.push_back(input);
    }

    if (!use_dynamic_size) {
        check_static_block();
    }
}

void bulk_handler::check_static_block() {
    if (commands_user.size() == static_size) {
        run = false;
        run_block();
    }
}