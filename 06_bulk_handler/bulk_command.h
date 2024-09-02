#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>

#include "bulk_io.h"

class bulk_command {
   protected:
    const std::string command;
    const bool instant_run;
    const std::time_t time_of_creation;
    const bulk_io& bulk_io_ref;

    bulk_command() = delete;  // initialize time and command on creation
   public:
    bulk_command(const std::string& _command, const bool _instant_run,
                 const bulk_io& _bulk_io_ref)
        : command(_command),
          instant_run(_instant_run),
          time_of_creation(std::time(nullptr)),
          bulk_io_ref(_bulk_io_ref) {}
    bulk_command(bulk_command& other) = delete;
    bulk_command(bulk_command&&) = delete;

    const std::time_t& get_creation_time() const { return time_of_creation; };
    virtual void command_action() = 0;
};

class bulk_command_basic : public bulk_command {
   public:
    using bulk_command::bulk_command;

    virtual void command_action() override {
        if (command == "help") {
            // bulk_io_ref.print_commands();
            // Will print the available commands
        } else {
            exit(0);
        }
    }
};

class bulk_command_custom : public bulk_command {
   public:
    using bulk_command::bulk_command;

    virtual void command_action() override {
        using namespace std::chrono_literals;
        std::cout << "Running: " << command << '\n';
        for (size_t i = 0; i <= 25; i++) {
            std::this_thread::sleep_for(5ms);
            std::cout << '.';
        }
        std::cout << "Done!" << std::endl;
    }
};