/**
 * @Author Enea Strambini
 * Library for matrix operations
 */

#include "MatrixLib.h"
#include <iostream>
#include <cstdlib>

using namespace std;

MATRIX_TYPE* initMatrix(MATRIX_TYPE* matrix, int matrixSize) {

    // Seeding random number generator
    srand(time(NULL));

    cout << "Initializing matrix MAX: " << MAX_RANDOM_NUMBER << endl;
    matrix = (MATRIX_TYPE*) malloc(matrixSize * matrixSize * sizeof(MATRIX_TYPE));

    for (int i = 0; i < matrixSize * matrixSize; i++) {
        matrix[i] = (MATRIX_TYPE) (rand() % MAX_RANDOM_NUMBER);
    }

#ifdef DEBUG
    cout << "Matrix initialized " << endl;
    printMatrix(matrix, matrixSize);
#endif
    return matrix;
}

void printMatrix(MATRIX_TYPE* matrix, int matrixSize) {
    cout << "Matrix: " << endl;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i * matrixSize + j] << " ";
        }
        cout << endl;
    }
}

