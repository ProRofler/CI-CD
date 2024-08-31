#pragma once

#include <memory>
#include <string>

class bulk_commands_handler
    : public std::enable_shared_from_this<bulk_commands_handler> {
   private:
    bool command_check(const std::string& input) const;
    void command_pass(const std::string& input) const;

    void state_check();
    bool is_dynamic_check() const;

   public:
    void handle_input(const std::string& input);

    std::shared_ptr<bulk_commands_handler> make_shared_to_this() {
        return shared_from_this();
    }
};