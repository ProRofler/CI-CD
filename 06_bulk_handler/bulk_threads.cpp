#include "bulk_threads.h"

#define UNUSED(variable) (void)variable

void bulk_threads::run_in_log_thread(std::function<void()> task) {
    log_tasks.push(task);
    log_condition.notify_one();
}
void bulk_threads::run_in_file_thread(std::function<void()> task) {
    file_tasks.push(task);
    file_condition.notify_one();
}

void bulk_threads::log_tasks_control() {
    tasks_loop(log_mtx, log_tasks, log_condition);
}

void bulk_threads::file_tasks_control() {
    tasks_loop(file_mtx, file_tasks, file_condition);
}

void bulk_threads::tasks_loop(std::mutex& mutex,
                              std::queue<std::function<void()>>& queue,
                              std::condition_variable& cv) {
    while (true) {
        std::function<void()> task;

        std::unique_lock<std::mutex> lock(mutex);
        if (!stop && queue.empty())
            return;
        else {
            cv.wait(lock, [this, queue] { return stop || !queue.empty(); });
            task = std::move(queue.front());
            queue.pop();
            task();
        }
    }
}
