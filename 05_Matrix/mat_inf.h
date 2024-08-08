#pragma once
#include <unordered_map>
#include <vector>

#include "vector_hash.h"

// infinite sparse matrix concept
template <typename T, T V>
class mat_inf {
   public:
    mat_inf() = delete;
    mat_inf(int dimensions_num);
    ~mat_inf();

    T& operator[](T val);

    // get
    size_t size() { return size_m; }

   private:
    // user input
    const T default_value;
    const int dimensions;

    // matrix related
    std::unordered_map<std::vector<int>, T, vector_hash> elemets_data;

    // utils
    size_t size_m = 0;

    void increase_size(int value) { size_m += value; }
    void decrease_size(int value) { size_m -= value; }

    //temp
    int arr[6] = {0,1,2,3,4,5};
};

#include "mat_inf.tpp"