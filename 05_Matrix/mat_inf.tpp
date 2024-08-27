#include <iostream>

#include "m_proxy.h"
#include "mat_inf.h"

template <typename T, T V, size_t N>
mat_inf<T, V, N>::mat_inf() : default_value(V) {
    if (dimensions < 1)
        throw std::logic_error(
            "Number of dimensions less than two are not allowed");
}

template <typename T, T V, size_t N>
auto mat_inf<T, V, N>::operator[](int index) -> decltype(auto) {
    return m_proxy<N - 1ULL, T, V, N>(*this, index);
}

template <typename T, T V, size_t N>
T mat_inf<T, V, N>::get_value(std::vector<int> coordinates) {
    if (data.find(coordinates) != data.end()) {
        return data.at(coordinates);
    } else {
        return default_value;
    }
}
template <typename T, T V, size_t N>
void mat_inf<T, V, N>::set_value(std::vector<int> coordinates, T value) {
    value == default_value ? data.erase(coordinates)
                           : data[coordinates] = value;
}

