#pragma once

#include <memory>
#include <string>

class bulk_builder;

class bulk_commands_handler {
   private:
    bulk_builder& builder;

    // commands related
    bool command_is_valid(const std::string& input) const;
    void command_pass(const std::string& input) const;

   public:
    bulk_commands_handler() = delete;
    bulk_commands_handler(bulk_builder& _builder) : builder(_builder) {}

    void handle_input(const std::string& input);
};