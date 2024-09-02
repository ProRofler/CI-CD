#pragma once

#include <memory>
#include <string>

class bulk_commands_handler;

class bulk_io {
   private:
    const std::shared_ptr<bulk_commands_handler> p_command_handler = nullptr;
    void clear_io_buffer();

   public:
    bulk_io() = delete;
    bulk_io(std::shared_ptr<bulk_commands_handler> p_com_handler)
        : p_command_handler(p_com_handler) {}

    // output
    void print_greeting() const;
    void print_commands() const;
    void print_mesage(const std::string& message) const;
    void print_run(const std::string& input) const;
    void print_exit() const;

    // input
    void input_command();
};