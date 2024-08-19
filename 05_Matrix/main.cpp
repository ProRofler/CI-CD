#include <assert.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "mat_inf.h"

int main() {
    mat_inf<int, -1> matrix;
    assert(matrix.size() == 0);

    auto a = matrix[2][3];
    assert(a == -1);
    assert(matrix.size() == 0);

    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
}