#include <array>
#include <iostream>

#include "mat_inf.h"

int main() {
    mat_inf<int, 3> mat(1);

    auto f = mat[2];
    std::cout << f << std::endl;

    mat[2] = 15;

    f = mat[2];
    std::cout << f << std::endl;

    return 0;
}