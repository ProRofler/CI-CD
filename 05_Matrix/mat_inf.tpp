#include "mat_inf.h"

#include <iostream>

template <typename T, T V>
mat_inf<T, V>::mat_inf()  : default_value(V) {
    p_mtx = new T[default_capacity];
}

template <typename T, T V>
mat_inf<T, V>::~mat_inf() { delete[] p_mtx; }

template <typename T, T V>
T mat_inf<T, V>::operator[](T val) {
    // return the element value
    std::cout << "Operator [] called" << std::endl;
    return val;
}