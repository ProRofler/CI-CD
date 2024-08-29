#pragma once

#include <assert.h>

#include <iostream>
#include <string>
#include <vector>

class bulk_handler {
   private:
    using commands = std::vector<std::string>;

    std::vector<std::string> commands_user;

    const size_t static_size;

    bool use_dynamic_size = false;

    void clear_io_buffer();

   public:
    bulk_handler() : commands_user(16), static_size(3) {};
    bulk_handler(int& argc) : commands_user(16), static_size(argc) {};

    void add_command();

    void run();
    void show_commands();
};