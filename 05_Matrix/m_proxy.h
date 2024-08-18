#pragma once
#include "mat_inf.h"

template <size_t dim, typename T, T V, size_t N>
class m_proxy {
    mat_inf<T, V, N>& matrix;

   public:
    // using Type = m_proxy<dim, T, V, N>&;

    m_proxy() = delete;
    m_proxy(mat_inf<T, V, N>& matrix_class) : matrix(matrix_class) {};

    auto operator[](int index) -> m_proxy<dim - 1, T, V, N> {
        matrix.handle_index(index);
        return m_proxy<dim - 1ULL, T, V, N>(matrix);
    }
};

template <typename T, T V, size_t N>
class m_proxy<1ULL, T, V, N> {
    mat_inf<T, V, N>& matrix;

   public:
    using Type = T&;

    m_proxy() = delete;
    m_proxy(mat_inf<T, V, N>& matrix_class) : matrix(matrix_class) {};

    T& operator[](int index) {
        matrix.handle_index(index);
        return matrix.data[matrix.handle_coords()];
    }
};