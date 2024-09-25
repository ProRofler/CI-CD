#include "bulk_threads.h"

void bulk_threads::run_in_log_thread(std::function<void()> task) {
    log(task);
    log.join();
}
void bulk_threads::run_in_file_thread(std::function<void()> task) {}