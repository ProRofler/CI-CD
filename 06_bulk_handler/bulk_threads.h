#pragma once

#include <condition_variable>
#include <functional>
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
        if (log_thread.joinable()) log_thread.join();
        if (file_1_thread.joinable()) file_1_thread.join();
        if (file_2_thread.joinable()) file_2_thread.join();
    }

    void run_in_log_thread(std::function<void()> task);
    void run_in_file_thread(std::function<void()> task);

   private:
    void log_tasks_control();
    void file_tasks_control();

    std::thread log_thread, file_1_thread, file_2_thread;

    std::queue<std::function<void()>> file_tasks;
    std::queue<std::function<void()>> log_tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;

    bool stop;
};