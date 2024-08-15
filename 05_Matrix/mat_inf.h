#pragma once
#include <iterator>
#include <unordered_map>
#include <vector>

// #include "index_collector.h"
#include "vector_hash.h"

// infinite sparse matrix concept
template <typename T, T V, size_t N = 2>
class mat_inf {
   private:
    T default_value;

    const size_t dimensions = N;
    std::unordered_map<std::vector<int>, T, vector_hash> data;

    // utils
    std::vector<int> coords;

    std::vector<int> handle_coords(const char* error_msg = "error\n");

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

    template <size_t dim>
    class m_proxy {
       public:
        auto operator[](int index) -> typename m_proxy<dim - 1>::Type {
            coords.push_back(index);
            return m_proxy<dim - 1ULL>()[index];
        }
    };

    // template <>
    // class m_proxy<1ULL> {
    //    public:
    //     using Type = T&;
    //     T& operator[](int index) {
    //         coords.push_back(index);
    //         return data[handle_coords()];
    //     }
    // };

   public:
    mat_inf();  // default constructor result in 2D matrix
    ~mat_inf() = default;

    auto operator[](int index) -> typename m_proxy<N>::Type;

    // get
    size_t size() { return data.size(); }

    auto begin() { return iter(data.begin()); }
    auto end() { return iter(data.end()); }
};

#include "mat_inf.tpp"