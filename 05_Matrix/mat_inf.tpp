#include <iostream>

#include "m_proxy.h"
#include "mat_inf.h"

template <typename T, T V, size_t N>
mat_inf<T, V, N>::mat_inf() : default_value(V), coords(N) {
    coords.reserve(N);
    if (dimensions < 1)
        throw std::logic_error(
            "Number of dimensions less than two are not allowed");
}

template <typename T, T V, size_t N>
auto mat_inf<T, V, N>::operator[](int index) -> decltype(auto) {
    handle_index(index);
    return m_proxy<N - 1ULL, T, V, N>(*this);
}

template <typename T, T V, size_t N>
std::vector<int> mat_inf<T, V, N>::handle_coords(const char* error_msg) {
    if (coords.size() != dimensions) {
        throw std::logic_error(error_msg);
    }

    std::vector<int> make_coords = std::move(coords);

    return make_coords;
}
template <typename T, T V, size_t N>
void mat_inf<T, V, N>::handle_index(int index) {

    for (auto a : coords){
        std::cout << "*******Data: " << a << '\n';
    }

    if (coords.size() >= dimensions)
        throw std::logic_error(
            "Number of indexes are over the number of dimensions");

    coords.push_back(index);
}

template <typename T, T V, size_t N>
T& mat_inf<T, V, N>::get_data(std::vector<int>& coordinates) const {
    return data.at(coordinates);
}