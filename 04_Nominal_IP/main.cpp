#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>  // integer func
typename std::enable_if<std::is_integral<T>::value, void>::type print_ip(
    T value) {
    std::cout << "integer output template " << value << std::endl;
}

template <typename T>  // string func, output as is
typename std::enable_if<std::is_same<T, std::string>::value>::type print_ip(
    T value) {
    std::cout << "string output template " << value << std::endl;
}

template <typename T>  // container func
auto print_ip(T value) -> decltype(value.sort()) {
    std::cout << "vector/list output " << std::endl;
}


int main() {

    print_ip(int8_t{-1});           // 255
    print_ip(int16_t{0});           // 0.0
    print_ip(int32_t{2130706433});  // 127.0.0.1
    print_ip(int64_t{8875824491850138409});

    print_ip(std::string{"Hello, World!"});

    //print_ip(std::vector<int>{100, 200, 300, 400});  // 100.200.300.400
    print_ip(std::list<short>{400, 300, 200, 100});  // 400.300.200.100

    return 0;
}