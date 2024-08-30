#pragma once

#include <string>

class bulk_io {
   public:
    // output
    void print_greeting() const;
    void print_commands() const;
    void print_error(const std::string& input) const;
    void print_actual(const std::string& input) const;
    void print_exit() const;

    // input
    void input_command();
};