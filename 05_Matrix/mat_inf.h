#pragma once
#include <iterator>
#include <unordered_map>
#include <vector>

// #include "index_collector.h"
#include "vector_hash.h"

template <size_t dim, typename T, T V, size_t N>
class m_proxy;

// infinite sparse matrix concept
template <typename T, T V, size_t N = 2>
class mat_inf {
   private:
    const T default_value;

    const size_t dimensions = N;
    std::unordered_map<std::vector<int>, T, vector_hash> data;

    T get_value(std::vector<int> coordinates);
    void set_value(std::vector<int> coordinates, T value);


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

    friend class m_proxy<1, T, V, N>;
    friend class m_proxy<N, T, V, N>;

   public:
    mat_inf();  // default constructor result in 2D matrix
    ~mat_inf() = default;

    auto operator[](int index) -> decltype(auto);

    // get
    size_t size() const { return data.size(); }
    auto begin() { return iter(data.begin()); }
    auto end() { return iter(data.end()); }
};

#include "mat_inf.tpp"