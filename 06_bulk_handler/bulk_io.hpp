#pragma once

#include <memory>
#include <string>

#include "bulk_commands_handler.hpp"


class bulk_io {
    const std::shared_ptr<bulk_commands_handler> p_command_handler = nullptr;

   public:
    bulk_io() {}

    // output
    void print_greeting() const;
    void print_commands() const;
    void print_error(const std::string& input) const;
    void print_actual(const std::string& input) const;
    void print_exit() const;

    // input
    void input_command();
};