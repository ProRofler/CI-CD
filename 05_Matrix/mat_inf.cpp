#include "mat_inf.h"

#include <iostream>

template <typename T, T V>
T mat_inf<T, V>::operator[](T val) {
    // return the element value
    std::cout << "Operator [] called" << std::endl;
    return val; 
}