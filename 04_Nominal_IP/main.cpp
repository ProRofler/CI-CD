#include <iostream>
#include <type_traits>

template<typename T> //integer fnunction
typename std::enable_if<std::is_integral<T>::value, void>::type print_ip_adress(T value){



    std::cout << "temp output" << std::endl;
}

int main(){

    

    return 0;
}