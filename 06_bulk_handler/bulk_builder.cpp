#include "bulk_builder.h"

void bulk_builder::create_system() {
    p_commands_handler = std::make_shared<bulk_commands_handler>(*this);
    p_io = std::make_unique<bulk_io>(p_commands_handler);
    p_logger = std::make_unique<bulk_logger>();
    p_state_machine = std::make_unique<bulk_state_machine>(p_commands_handler);
}