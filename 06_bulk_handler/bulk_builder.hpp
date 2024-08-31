#pragma once

#include <memory>

// forward declarations
class bulk_commands_handler;
class bulk_io;
class bulk_logger;

class bulk_builder {
   private:
    std::shared_ptr<bulk_commands_handler> p_commands_handler = nullptr;
    std::unique_ptr<bulk_io> p_io;
    std::unique_ptr<bulk_logger> p_logger;

   public:
    void create_system();
};