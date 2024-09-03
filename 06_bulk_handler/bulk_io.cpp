#include "bulk_io.h"

#include <iostream>
#include <limits>

#include "bulk_commands_handler.h"

// output
void bulk_io::print_greeting() const {
    std::cout
        << "Welcome to the commands handler prototype. Insert a command or "
           "type \"help\" for options. Or type \"exit\" to stop the program.\n";
}

void bulk_io::print_mesage(const std::string& message) const {
    std::cout << message << std::endl;
}

// input
void bulk_io::clear_io_buffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

void bulk_io::input_command() {
    std::string u_input;
    std::getline(std::cin >> std::ws, u_input);
    p_command_handler->handle_input(u_input);
}

void bulk_io::print_commands() const {
    std::cout << "If I werent't lazy you would've seen a list of available "
                 "commands here!"
              << std::endl;
}