#pragma once

#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

class bulk_threads {
   public:
    bulk_threads() : stop(false) {
        log_thread = std::thread(&bulk_threads::log_tasks_control, this);
        file_1_thread = std::thread(&bulk_threads::file_tasks_control, this);
        file_2_thread = std::thread(&bulk_threads::file_tasks_control, this);
    }

    ~bulk_threads() {
        stop = true;
        if (log_thread.joinable()) log_thread.join();
        if (file_1_thread.joinable()) file_1_thread.join();
        if (file_2_thread.joinable()) file_2_thread.join();
    }

    void run_in_log_thread(const std::function<void()> task);
    void run_in_file_thread(const std::function<void()> task);

   private:
    void log_tasks_control();
    void file_tasks_control();
    void tasks_loop(std::mutex& mutex, std::queue<std::function<void()>>& queue,
                    std::condition_variable& cv);

    std::thread log_thread, file_1_thread, file_2_thread;

    std::queue<std::function<void()>> file_tasks;
    std::queue<std::function<void()>> log_tasks;

    std::mutex file_mtx, log_mtx;
    std::condition_variable file_condition, log_condition;

    bool stop;
};