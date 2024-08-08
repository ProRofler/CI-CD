#pragma once

#include <vector>
#include <functional>

// Хеш-функция для std::vector
struct vector_hash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::size_t hash = 0;
        for (int num : v) {
            hash ^=
                std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};