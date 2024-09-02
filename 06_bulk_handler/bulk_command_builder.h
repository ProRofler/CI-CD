#pragma once

#include <memory>

#include "bulk_command.h"

class bulk_command_builder {
   public:
    virtual std::unique_ptr<bulk_command> make_command(
        const std::string& command) = 0;
};

class bulk_command_builder_basic : bulk_command_builder {
   public:
    virtual std::unique_ptr<bulk_command> make_command(
        const std::string& command) {
        return std::make_unique<bulk_command_basic>();
    };
};

class bulk_command_builder_custom : bulk_command_builder {
   public:
    virtual std::unique_ptr<bulk_command> make_command(
        const std::string& command) {
        return std::make_unique<bulk_command_custom>();
    };
};