#pragma once

#include <memory>
#include <vector>

//NOT NEEDED but I'll keep it here just for future references

template <typename T, T V>
class mat_inf;

template <typename T, T V>
class index_collector {
   private:
    std::shared_ptr<mat_inf<T, V>> _matrix;

   public:
    index_collector(std::shared_ptr<mat_inf<T, V>> matrix) : _matrix(matrix) {}

    index_collector& operator[](int index) {
        _matrix->add_coord(index);
        return *this;
    }

    std::vector<int> to_vector() const { return _matrix->get_coords(); }

    operator std::vector<T>() const { return to_vector(); }
};