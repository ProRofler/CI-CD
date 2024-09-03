#include "bulk_main.h"

#include "bulk_io.h"

void bulk_main::start() {
    p_builer = std::make_unique<bulk_builder>();
    while (run) {
        p_builer->get_io_ptr()->print_greeting();
        p_builer->get_io_ptr()->input_command();
    }
}