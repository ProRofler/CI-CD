#include <iostream>
#include <type_traits>
#include <cstdint>
#include <string>


// template<typename T> //string fnunction, output as is
// auto print_ip(T value) -> decltype(value.c_str()) {
//     std::cout << "string output " << value << std::endl;}

template<typename T> //integer fnunction
typename std::enable_if<std::is_integral<T>::value, void>::type print_ip(T value){
    std::cout << "integer output " << value << std::endl;
}

template<typename T> //integer fnunction
typename std::enable_if<std::is_same<T, std::string>::value>::type print_ip(T value){
    std::cout << "string output " << value << std::endl;
}




int main(){

    print_ip( int8_t{-1} ); // 255
    print_ip( int16_t{0} ); // 0.0
    print_ip( int32_t{2130706433} ); // 127.0.0.1
    print_ip( int64_t{8875824491850138409} );

    print_ip(std::string{"Hello, World!"});

    return 0;
}