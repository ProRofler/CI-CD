#pragma once

#include <memory>

#include "bulk_command.h"

class bulk_io;

class bulk_command_builder {
   public:
    virtual std::unique_ptr<bulk_command> build_command(
        const std::string& command, const bulk_io& io_ptr) = 0;
};

class bulk_command_builder_basic : bulk_command_builder {
   public:
    virtual std::unique_ptr<bulk_command> build_command(
        const std::string& command, const bulk_io& io_ptr) override {
        return std::make_unique<bulk_command_basic>(command, true, io_ptr);
    };
};

class bulk_command_builder_custom : bulk_command_builder {
   public:
    virtual std::unique_ptr<bulk_command> build_command(
        const std::string& command, const bulk_io& io_ptr) override {
        return std::make_unique<bulk_command_custom>(command, false, io_ptr);
    };
};