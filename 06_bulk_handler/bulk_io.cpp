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

void bulk_io::print_error(const std::string& err_msg) const {
    std::cout << err_msg << std::endl;
}

// input
void bulk_io::clear_io_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void bulk_io::input_command() {
    std::string u_input;
    std::cin >> u_input >> std::ws;
    clear_io_buffer();
    p_command_handler->handle_input(u_input);
}
