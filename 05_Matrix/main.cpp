#include <vector>
#include <iostream>

#include "mat_inf.h"

int main() {
    mat_inf<int, 3> mat;

    //mat[2][1] = 14;

    //auto f = mat[2][1];
    std::cout << mat[2][1] << std::endl;

    return 0;
}