#pragma once
#include <unordered_map>
#include <vector>

#include "vector_hash.h"

// infinite sparse matrix concept
template <typename T, T V>
class mat_inf {
   private:
    // user input
    const T default_value;
    const int dimensions;

    // matrix related
    std::unordered_map<std::vector<int>, T, vector_hash> elemets_data;

   public:
    mat_inf() = delete;
    mat_inf(int dimensions_num);
    ~mat_inf();

    T& operator[](int index);

    // get
    size_t size() { return elemets_data.size(); }
};

#include "mat_inf.tpp"