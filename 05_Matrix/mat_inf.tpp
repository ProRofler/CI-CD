#include <iostream>

#include "mat_inf.h"

template <typename T, T V>
mat_inf<T, V>::mat_inf() : default_value(V), dimensions(2), temp_coords(2) {
    temp_coords.reserve(2);
}
template <typename T, T V>
mat_inf<T, V>::mat_inf(int dimensions_num)
    : default_value(V),
      dimensions(dimensions_num),
      temp_coords(dimensions_num) {
    temp_coords.reserve(dimensions_num);
}

template <typename T, T V>
mat_inf<T, V>::m_proxy mat_inf<T, V>::operator[](int index) {
    std::cout << "Operator [] called!\n";
    if (dimension_contol >= temp_coords.size()) {
        throw std::logic_error("Wrong number of dimensions op[] ");
    }

    return m_proxy(*this, std::vector<int>{index});
}

template <typename T, T V>
mat_inf<T, V>::operator T() {
    std::cout << "Operator () called! return T\n";

    if (data.find(handle_coords()) == data.end()) {
        return default_value;
    } else {
        return data.at(handle_coords());
    }
}

template <typename T, T V>
T& mat_inf<T, V>::operator=(T& value) {
    std::cout << "Operator = called!\n";
    std::cout << "start of = " << temp_coords.size() << '\n';

    // handle_coords return a vector
    if (value != default_value) {
        data.at(handle_coords()) = value;
    } else {
        data.erase(handle_coords());
    }
    return &value;
}

template <typename T, T V>
std::vector<int> mat_inf<T, V>::handle_coords(const char* error_msg) {
    if (temp_coords.size() != dimensions) {
        throw std::logic_error(error_msg);
    }

    std::vector<int> coords = std::move(temp_coords);
    // temp_coords.clear();
    dimension_contol = 0;

    return temp_coords;
}