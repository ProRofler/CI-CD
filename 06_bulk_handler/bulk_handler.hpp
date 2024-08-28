#pragma once

#include <assert.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class bulk_handler {
   private:
    using commands = std::vector<std::string>;

    commands commands_user;
    commands commands_list;

    const int static_size;
    int dynamic_size;

    bool use_dynamic_size = false;

    void make_commands_list();

   public:
    bulk_handler() : static_size(3) { make_commands_list(); };
    bulk_handler(int& argc) : static_size(argc) { make_commands_list(); };

    void add_command(const std::string& input) {
        commands_user.push_back(input);
    }

    void run();
};