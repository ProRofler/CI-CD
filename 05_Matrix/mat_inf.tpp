#include <iostream>

#include "mat_inf.h"

template <typename T, T V>
mat_inf<T, V>::mat_inf() : default_value(V), dimensions(2) {}

template <typename T, T V>
mat_inf<T, V>::mat_inf(int dimensions_num)
    : default_value(V), dimensions(dimensions_num) {}

template <typename T, T V>
mat_inf<T, V>& mat_inf<T, V>::operator[](int index) {
    temp_coords.push_back(index);
    return *this;
}

template <typename T, T V>
mat_inf<T, V>::operator T() {
    if (temp_coords.size() != dimensions)
        throw std::logic_error("Wrong number of dimensions");

    std::vector<int> coords = temp_coords;
    temp_coords.clear();

    return data[coords];
}

template <typename T, T V>
mat_inf<T,V>& mat_inf<T, V>::operator=(T value) {
    if (temp_coords.size() != dimensions)
        throw std::logic_error("Wrong number of dimensions");

    std::vector<int> coords = temp_coords;
    temp_coords.clear();

    data[coords] = value;

    return *this;
}