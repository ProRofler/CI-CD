#pragma once

#include <memory>
#include <string>

class bulk_builder;

class bulk_commands_handler {
   private:
    bool command_check(const std::string& input) const;
    void command_pass(const std::string& input) const;

    void state_check();
    bool is_dynamic_check() const;

    bulk_builder& builder;

   public:
    bulk_commands_handler() = delete;
    bulk_commands_handler(bulk_builder& _builder) : builder(_builder) {}

    void handle_input(const std::string& input);
};