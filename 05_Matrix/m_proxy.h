#pragma once
#include <assert.h>

#include "mat_inf.h"

template <size_t dim, typename T, T V, size_t N>
class m_proxy {
    using coords = std::vector<int>;
    mat_inf<T, V, N>& matrix;
    coords _coords;

   public:
    // using Type = m_proxy<dim, T, V, N>&;

    m_proxy() = delete;
    m_proxy(mat_inf<T, V, N>& matrix_class, coords coordinates)
        : matrix(matrix_class) {};
    m_proxy(mat_inf<T, V, N>& matrix_class, int index) : matrix(matrix_class) {
        _coords.push_back(index);
    };

    auto operator[](int index) & -> decltype(auto) {
        _coords.push_back(index);
        return m_proxy<dim - 1ULL, T, V, N>(matrix, _coords);
    }
};

template <typename T, T V, size_t N>
class m_proxy<1ULL, T, V, N> {
    using coords = std::vector<int>;
    mat_inf<T, V, N>& matrix;
    coords _coords;

   public:
    using Type = T&;

    m_proxy() = delete;
    m_proxy(mat_inf<T, V, N>& matrix_class, coords coordinates)
        : matrix(matrix_class), _coords(coordinates) {};
    m_proxy(mat_inf<T, V, N>& matrix_class, int index) : matrix(matrix_class) {
        _coords.push_back(index);
    };

    T& operator[](int index) {
        _coords.push_back(index);
        if (_coords.size() > matrix.dimensions) {
            throw std::logic_error(
                "Dimensions mismatch");
        }

        return matrix.data[_coords];
    }

    void operator=(T value) & { matrix.set_value(_coords, value); }
};