#include "bulk_threads.h"

void bulk_threads::run_in_log_thread(const std::function<void()> task) {
    log_tasks.push(task);
    log_condition.notify_one();
}
void bulk_threads::run_in_file_thread(const std::function<void()> task) {
    {
        std::lock_guard<std::mutex> lock(file_mtx);
        file_tasks.push(task);
    }
    file_condition.notify_one();
}

void bulk_threads::log_tasks_control() {
    // tasks_loop(log_mtx, log_tasks, log_condition);
}

void bulk_threads::file_tasks_control() {
    tasks_loop(file_mtx, file_tasks, file_condition);
}

void bulk_threads::tasks_loop(std::mutex& mutex,
                              std::queue<std::function<void()>>& queue,
                              std::condition_variable& cv) {
    std::unique_lock<std::mutex> lock(mutex);
    while (true) {
        if (stop && queue.empty())
            return;
        else if (!stop && !queue.empty()) {
            std::function<void()> task;
            cv.wait(lock, [this, queue] { return stop || !queue.empty(); });
            task = std::move(queue.front());
            queue.pop();
            task();
        } else {
            continue;
        }
    }
}
