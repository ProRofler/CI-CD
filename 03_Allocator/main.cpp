#include <memory>
#include <map>
#include <iostream>
#include <limits>
#include <vector>

#define UNUSED(variable) (void)variable



template <typename T> 
class allocator_log{

  public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    
    using void_pointer = void*;
    using const_void_pointer = const void*;

    using size_type = size_t;

    using difference_type = std::ptrdiff_t;

    template <typename U>
    struct rebind{
        using other = allocator_log<U>;
    };


    allocator_log() = default;
    template <typename U>
    allocator_log(const allocator_log<U> &other){UNUSED(other);}

    ~allocator_log() = default;

    pointer allocate(std::size_t n){
        num_allocations += n;
        return reinterpret_cast<pointer>(operator new[](sizeof(T) * n));
    }

    pointer allocate(std::size_t n, const_void_pointer hint){
        UNUSED(hint);
        return allocate(n);
    }

    void deallocate(pointer p, std::size_t n) noexcept{
        std::cout << "\nDeallocating " << n << " elements.\n";
        operator delete(p);
    }

    size_type max_size() const{
        return std::numeric_limits<size_type>::max();
    }

    template <typename U, typename... Args>
    void construct(U *p, Args && ...args){
        new(p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U *p){
        p->~U();
    }

    size_t get_allocations(){
        return num_allocations;
    }
  
  private:
    static size_t num_allocations;

};

template <typename T>
typename allocator_log<T>::size_type allocator_log<T>::num_allocations = 0;

int main(){

std::map <int, bool, std::less<int>, allocator_log<std::pair<int, bool>>> log_map;
log_map.emplace(std::make_pair(2, true));
std::cout << log_map.get_allocator().get_allocations();

// std::vector<int, allocator_log<int>> vec = {1,2,3,4};
// std::cout << vec[2] << "\n" << vec.get_allocator().get_allocations() << '\n';
// vec.push_back(5);
// std::cout << vec[2] << "\n" << vec.get_allocator().get_allocations() << '\n';
// vec.push_back(6);
// std::cout << vec[2] << "\n" << vec.get_allocator().get_allocations() << '\n';



     return 0;
}