#pragma once

#include <iostream>
#include <string>
#include <vector>

class bulk_handler {
   private:
    std::vector<std::string> commands;

   public:
    void add_command(std::string& input) { commands.push_back(input); }

    void bulk() {
        std::cout << "Bulk: ";
        for (size_t i = 0; i < commands.size(); i++) {
            std::cout << commands.at(i);
            if (i < commands.size() - 1ULL) {
                std::cout << ", ";
            } else {
                std::cout << std::endl;
            }
        }
    }
};