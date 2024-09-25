#pragma once

#include <functional>
#include <thread>

class bulk_threads {
   public:
    void run_in_log_thread(std::function<void()> task);
    void run_in_file_thread(std::function<void()> task);

   private:
    std::thread log, file_1, file_2;

    static size_t counter;
};