#include <cstdlib>
#include "MatrixLib.h"


int main() {
    MATRIX_TYPE* matrix;

    int matrixSize = 3;
    matrix = initMatrix(matrix, matrixSize);

    free(matrix);

    return 0;
}