#include <iostream>

#include "mat_inf.h"

template <typename T, T V>
mat_inf<T, V>::mat_inf() : default_value(V), dimensions(2), temp_coords(2) {
    temp_coords.shrink_to_fit();
}
template <typename T, T V>
mat_inf<T, V>::mat_inf(int dimensions_num)
    : default_value(V),
      dimensions(dimensions_num),
      temp_coords(dimensions_num) {
    temp_coords.shrink_to_fit();
}

template <typename T, T V>
typename mat_inf<T, V>::m_proxy mat_inf<T, V>::operator[](int index) {
    std::cout << "Operator [] called!\n";
    if (dimension_contol >= temp_coords.size()) {
        throw std::logic_error("Wrong number of dimensions op[] ");
    }
    temp_coords[dimension_contol] = index;
    dimension_contol++;
    return m_proxy{*this, index};
}

template <typename T, T V>
mat_inf<T, V>::operator T() {
    std::cout << "Operator () called! return T\n";
    std::cout << "start of () " << temp_coords.size() << '\n';
    if (temp_coords.size() != dimensions) {
        throw std::logic_error("Wrong number of dimensions op() ");
    }
    std::vector<int> coords = temp_coords;
    temp_coords.clear();
    std::cout << "after clear in () " << temp_coords.size() << '\n';
    dimension_contol = 0;

    if (data.find(coords) == data.end()) {
        return default_value;
    }

    return data[coords];
}

template <typename T, T V>
mat_inf<T, V>& mat_inf<T, V>::operator=(T value) {
    std::cout << "Operator = called!\n";
    std::cout << "start of = " << temp_coords.size() << '\n';
    if (temp_coords.size() != dimensions) {
        throw std::logic_error("Wrong number of dimensions op= ");
    }

    std::vector<int> coords = temp_coords;
    temp_coords.clear();
    std::cout << "after clear in = " << temp_coords.size() << '\n';
    dimension_contol = 0;

    if (value == default_value) {
        data.erase(coords);
        return *this;
    }

    data[coords] = value;

    return *this;
}