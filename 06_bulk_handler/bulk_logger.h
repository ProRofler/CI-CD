#pragma once

#include <vector>

class bulk_logger final {
   public:
    void save_to_log(const std::vector<std::string>& commands);
};
