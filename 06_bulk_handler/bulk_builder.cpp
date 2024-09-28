#include "bulk_builder.h"

void bulk_builder::create_system() {
    p_commands_handler = std::make_shared<bulk_commands_handler>(*this);
    p_io = std::make_unique<bulk_io>(p_commands_handler);
    p_logger = std::make_unique<bulk_logger>();
    p_runner = std::make_unique<bulk_runner>(*p_logger, *p_threads);
    p_threads = std::make_unique<bulk_threads>();
    p_command_builder_basic = std::make_unique<bulk_command_builder_basic>();
    p_command_builder_custom = std::make_unique<bulk_command_builder_custom>();
}