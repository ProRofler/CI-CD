#include <iostream>

#include "mat_inf.h"

template <typename T, T V>
mat_inf<T, V>::mat_inf(int dimensions_num)
    : default_value(V), dimensions(dimensions_num) {}

template <typename T, T V>
mat_inf<T, V>::~mat_inf() {}

template <typename T, T V>
T& mat_inf<T, V>::operator[](int index) {
    // return the element value
    std::cout << "Operator [] called" << std::endl;

    std::vector<int> coords;
    coords.push_back(index);

    return elemets_data[coords];
}