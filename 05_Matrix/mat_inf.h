#pragma once

template <typename T, T V>
class mat_inf {
   public:
    mat_inf();

    ~mat_inf();

    T operator[](T val);

    unsigned long long size() { return size_a; }

   private:
    // user defined
    T type;
    const T default_value;

    // matrix related
    T* p_mtx;

    // utils
    unsigned long long size_a = 0;
    const int default_capacity = 10;

    void increase_size(unsigned long long value) { size_a += value; }
    void decrease_size(unsigned long long value) { size_a -= value; }
};

#include "mat_inf.tpp"