#pragma once
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

   public:
    mat_inf();                    // default constructor result in 2D matrix
    mat_inf(int dimensions_num);  // constructor for N-dimensional matrix
                                  // defined by user
    ~mat_inf() = default;

    operator T();
    mat_inf<T,V>& operator=(T value);
    
    mat_inf<T, V>& operator[](int index);

    // get
    size_t size() { return data.size(); }
    std::vector<int> get_coords() { return temp_coords; }
    void add_coord(int index) { temp_coords.push_back(index); }
};

#include "mat_inf.tpp"