#include "bulk_threads.h"

#define UNUSED(variable) (void)variable

void bulk_threads::run_in_log_thread(std::function<void()> task) {
    UNUSED(task);
}
void bulk_threads::run_in_file_thread(std::function<void()> task) {
    UNUSED(task);
}