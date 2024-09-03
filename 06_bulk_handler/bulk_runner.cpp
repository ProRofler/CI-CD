#include "bulk_runner.h"

#include "bulk_command.h"
#include "bulk_logger.h"

bool bulk_runner::is_full() const { return queue.size() == static_size; }

void bulk_runner::add_to_bulk(std::unique_ptr<bulk_command> command) {
    queue.push_back(std::move(command));
    if (!dynamic && is_full()) {
        run_queue();
    }
}

void bulk_runner::run_queue() {
    for (auto& com : queue) {
        com->command_action();
    };
    logger.save_to_log(queue);
    queue.clear();
}

void bulk_runner::switch_state(const char& input) {
    switch (dynamic) {
        case true:
            if (input == '}') dynamic = !dynamic;
            if (!is_queue_empty()) run_queue();
            break;

        default:
            if (input == '{') dynamic = !dynamic;
            if (!is_queue_empty()) run_queue();
            break;
    }
}