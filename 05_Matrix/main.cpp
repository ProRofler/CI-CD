#include <assert.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "mat_inf.h"

int main() {
    mat_inf<int, -1> matrix;
    assert(matrix.size() == 0);

    [[maybe_unused]] auto a = matrix[2][3];
    assert(a == -1);
    assert(matrix.size() == 0);

    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);

    for (int i = 0; i < 10; i++) {
        for (int j = 9; j > 0; j--) {
            matrix[i][j] = j - i;
        }
    }

    for (auto c : matrix) {
        std::cout << c << '\n';
    }

    //

    mat_inf<int, -3, 4> matrix_4d;
    assert(matrix_4d.size() == 0);

    [[maybe_unused]] auto b = matrix_4d[2][3][2][5];
    assert(b == -3);
    assert(matrix_4d.size() == 0);

    matrix_4d[2][3][2][5] = 314;
    assert(matrix_4d[2][3][2][5] == 314);
    assert(matrix_4d.size() == 1);

    for (int i = 0; i < 10; i++) {
        for (int j = 9; j > 0; j--) {
            matrix_4d[i][j][i][j] = j - i;
        }
    }

    for (auto c : matrix_4d) {
        std::cout << c << '\n';
    }
}