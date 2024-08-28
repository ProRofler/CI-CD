#include "bulk_handler.hpp"

void bulk_handler::make_commands_list() {
    std::fstream file("commands.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file!");
    }

    std::string cmd;
    while (std::getline(file, cmd)) {
        commands_list.reserve(16);
        commands_list.push_back(cmd);
        assert(!commands_list.empty());
    }
}

void bulk_handler::run() {
    // run all commands
}