#pragma once

#include <ctime>
#include <string>

class bulk_command {
   private:
    const std::time_t time_of_creation;
    const std::string command;

    bulk_command();  // initialize time and command on creation
    bulk_command(bulk_command& other) = delete;
    bulk_command(bulk_command&& other) = delete;

   public:
    const std::time_t& get_creation_time() const { return time_of_creation; };
    const std::string& get_command() const { return command; };
};