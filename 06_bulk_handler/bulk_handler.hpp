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

    bool run = true;
    bool use_dynamic_size = false;

    void show_commands();
    std::string get_user_input();
    void run_block();

    void clear_io_buffer();
    void check_input(const std::string& input);
    void check_static_block();
    void handle_dynamic_block(const std::string& input);

   public:
    bulk_handler() : static_size(3) { commands_user.reserve(16); };
    bulk_handler(int& argc) : static_size(argc) { commands_user.reserve(16); };

    void start();
};