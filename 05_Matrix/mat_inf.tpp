#include <iostream>

#include "mat_inf.h"

template <typename T, T V, size_t N>
mat_inf<T, V, N>::mat_inf() : default_value(V), coords(N) {
    coords.reserve(N);
}

template <typename T, T V, size_t N>
auto mat_inf<T, V, N>::operator[](int index) -> typename m_proxy<N>::Type {
    coords.push_back(index);
    return m_proxy<N>()[index];
}

template <typename T, T V, size_t N>
std::vector<int> mat_inf<T, V, N>::handle_coords(const char* error_msg) {
    if (coords.size() != dimensions) {
        throw std::logic_error(error_msg);
    }

    std::vector<int> make_coords = std::move(coords);

    return make_coords;
}
