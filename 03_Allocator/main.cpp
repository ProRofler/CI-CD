#include <memory>
#include <map>
#include <iostream>


template <typename T> 
struct allocator_log{

    using value_type = T;

    allocator_log();

    template <typename U>
    allocator_log(const allocator_log<U>&);

    T* allocate(std::size_t n);

    void deallocate(T* p, std::size_t n);

};


int main(){

std::map <int, bool, std::less<int>, allocator_log<std::pair<int, bool>>> log_map;

log_map.emplace(std::make_pair(2, true));

std::cout << log_map.at(1);

    return 0;
}