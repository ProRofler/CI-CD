#include "bulk_main.h"

#include "bulk_io.h"
#include "bulk_runner.h"

void bulk_main::start() {
    p_builer = std::make_unique<bulk_builder>();
    while (true) {
        if (p_builer->get_runner_ptr()->is_queue_empty()) {
            p_builer->get_io_ptr()->print_greeting();
        }
        p_builer->get_io_ptr()->input_command();
    }
}