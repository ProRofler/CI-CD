#pragma once

template <typename T, T V>
class mat_inf {
    
    public:

    mat_inf() = default;
    
    ~mat_inf() = default;

    T operator[](T val);

    unsigned int size(){return size_a;}

    private:

    // user defined
    T type;
    T default_value;

    // utils

    unsigned int size_a = 0;


};


