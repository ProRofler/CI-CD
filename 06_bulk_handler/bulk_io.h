#pragma once

#include <memory>
#include <string>

class bulk_commands_handler;

class bulk_io {
    const std::shared_ptr<bulk_commands_handler> p_command_handler = nullptr;

   public:
    bulk_io() = delete;
    bulk_io(std::shared_ptr<bulk_commands_handler> p_com_handler)
        : p_command_handler(p_com_handler) {}

    // output
    void print_greeting() const;
    void print_commands() const;
    void print_error(const std::string& input) const;
    void print_actual(const std::string& input) const;
    void print_exit() const;

    // input
    void input_command();
};