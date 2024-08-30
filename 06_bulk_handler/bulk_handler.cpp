#include "bulk_handler.hpp"

#include <algorithm>
#include <chrono>
#include <ctime>
#include <limits>

#include "bulk_logger.hpp"

#define find_in_list(list)                       \
    (std::find(cmds_list::commands_list.begin(), \
               cmds_list::commands_list.end(), input))

#include "bulk_commands_list.hpp"

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
    for (auto& c : cmds_list::commands_list) {
        std::cout << "- " << c << std::endl;
    }
}

void bulk_handler::run_block() {
    std::cout << "Number of commands: " << commands_user.size()
              << "\nOhhh so much commands to run!!" << std::endl;

    commands_user.clear();
}

void bulk_handler::clear_io_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void bulk_handler::check_input(const std::string& input) {
    if (input == "help") {
        show_commands();
    } else if (input == "exit") {
        exit(0);
    } else if (input == "{" || input == "}") {
        handle_dynamic_block(input);
    } else if (find_in_list(cmds_list) == cmds_list::commands_list.end()) {
        std::cout << "Invalid command" << std::endl;
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

void bulk_handler::handle_dynamic_block(const std::string& input) {
    if (input == "}" && use_dynamic_size) {
        use_dynamic_size = false;
        run_block();

    } else if (input == "{" && !use_dynamic_size) {
        use_dynamic_size = true;
        if (!commands_user.empty()) {
            run_block();
        }
    }
}
