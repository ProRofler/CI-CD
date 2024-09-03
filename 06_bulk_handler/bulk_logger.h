#pragma once

#include <fstream>
#include <vector>

#include "bulk_command.h"

class bulk_logger final {
   public:
    void save_to_log(const std::vector<std::unique_ptr<bulk_command>>& queue) {
        auto time = queue.at(0)->get_creation_time();
        auto name = "bulk_" + std::to_string(time);

        std::ofstream log_file(name);

        if (log_file.is_open()) {
            log_file << "List of inserted commands: " << std::endl;
            for (auto& c : queue) {
                log_file << c->get_command_name() << std::endl;
            }
            log_file << "************";
        }
    }
};
