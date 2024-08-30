#pragma once

class bulk_logger {
   private:
    std::time_t log_time;

   public:
    void save_to_log(const std::vector<std::string>& commands);
    void set_time(const std::time_t& time);
};