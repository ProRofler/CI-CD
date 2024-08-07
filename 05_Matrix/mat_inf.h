#pragma once
#include <vector>

// infinite sparse matrix concept

template <typename T, T V>
class mat_inf {
   public:
    mat_inf() = delete;

    mat_inf(int dimensions_num);

    ~mat_inf();

    T operator[](T val);

    unsigned long long size() { return size_a; }

   private:
    // user defined
    T type;
    const T default_value;

    // matrix related
    struct matrix_value {
        T value;
        std::vector<int> dimensions;
    };

    matrix_value matrix_data;

    // utils
    size_t size_a = 0;

    void increase_size(int value) { size_a += value; }
    void decrease_size(int value) { size_a -= value; }
};

#include "mat_inf.tpp"