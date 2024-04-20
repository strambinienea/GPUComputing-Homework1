#include <cstdlib>
#include <iostream>
#include <MatrixLib.h>
using namespace std;

int main(int argc, char** argv) {

    // Check the size of the matrix is passed as an argument
    if (argc < 2) {
        cout
        << "You must specify the size of the matrix as an argument."
        << "The number will be an exponent for a power of 2"
        << endl;

        return -1;
    }

    bool debug = false;
#ifdef DEBUG
    debug = true;
#endif

    // Calculate the size of the matrix and initialize it
    int matrixSize = 1 << atoi(argv[1]);

    MATRIX_TYPE* matrix = nullptr;
    MATRIX_TYPE *transposedMatrix, *tiledTransposedMatrix = nullptr;

    matrix = initMatrix(matrixSize);
    transposedMatrix = initMatrix(matrixSize, false);
    tiledTransposedMatrix = initMatrix(matrixSize, false);

    // Compute the transpose of the matrix
    transposeMatrix(matrix, transposedMatrix, matrixSize);

    // Compute the transpose of the matrix using a tiled approach
    transposeMatrixTiled(matrix, tiledTransposedMatrix, matrixSize, 2, debug);

    free(matrix);
    free(transposedMatrix);
    free(tiledTransposedMatrix);

    return 0;
}
