#pragma once
#include <iterator>
#include <unordered_map>
#include <vector>

// #include "index_collector.h"
#include "vector_hash.h"

// infinite sparse matrix concept
template <typename T, T V>
class mat_inf {
   private:
    // user input
    const T default_value;
    const size_t dimensions;

    // matrix related
    std::unordered_map<std::vector<int>, T, vector_hash> data;

    // utils
    std::vector<int> temp_coords;
    size_t dimension_contol = 0;

    class iter {
       public:
        using map_iter = typename std::unordered_map<std::vector<int>, T,
                                                     vector_hash>::iterator;

        iter(map_iter iter) : mapIter(iter) {}

        T& operator*() const { return mapIter->second; }

        iter& operator++() {
            ++mapIter;
            return *this;
        }

        bool operator!=(const iter& other) const {
            return mapIter != other.mapIter;
        }

       private:
        map_iter mapIter;
    };

    struct m_proxy {
        mat_inf& parent;
        int index;

        operator int() const {
            parent(index);
            return index;
        }
    };

   public:
    mat_inf();                    // default constructor result in 2D matrix
    mat_inf(int dimensions_num);  // constructor for N-dimensional matrix
                                  // defined by user
    ~mat_inf() = default;

    operator T();
    mat_inf<T, V>& operator=(T value);
    m_proxy operator[](int index);
    // T& operator*() const { return *data; }

    // get
    size_t size() { return data.size(); }
    std::vector<int> get_coords() { return temp_coords; }

    auto begin() { return iter(data.begin()); }
    auto end() { return iter(data.end()); }
};

#include "mat_inf.tpp"