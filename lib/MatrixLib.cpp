/**
 * @Author Enea Strambini
 * @brief Library for matrix operations
 */

#include <MatrixLib.h>
#include <iostream>
#include <cstdlib>

using namespace std;

MATRIX_TYPE* initMatrix(int matrixSize, bool generateValue) {

    // Seeding random number generator
    srand(time(NULL));

    cout << "Initializing a new matrix of size " << matrixSize << endl;
    auto matrix = (MATRIX_TYPE*) malloc(matrixSize * matrixSize * sizeof(MATRIX_TYPE));

    if (!generateValue) {
        cout << "Matrix wil be left empty" << endl;
    } else {
        for (int i = 0; i < matrixSize * matrixSize; i++) {
            matrix[i] = (MATRIX_TYPE) rand();
        }
    }
    return matrix;
}

void transposeMatrix(const MATRIX_TYPE* matrix, MATRIX_TYPE* transposedMatrix, int matrixSize, bool debug) {

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            transposedMatrix[i * matrixSize + j] = matrix[j * matrixSize + i];
        }
    }

    if (debug) {
        cout << "Matrix transposed using the naive approach." << endl;
        cout << "Original matrix: " << endl;
        printMatrix(matrix, matrixSize);
        cout << "Transposed matrix: " << endl;
        printMatrix(transposedMatrix, matrixSize);
    }
}

void transposeMatrixTiled(
        const MATRIX_TYPE* matrix,
        MATRIX_TYPE* transposedMatrix,
        int matrixSize,
        int tileGridSize,
        bool debug
    ) {

    // Size of the side of a block
    int tileSize = matrixSize / tileGridSize;
    // the dimension of a block, i.e. the number of elements it "contains"
    int tileDimension = tileSize * tileSize;

    if (debug) {
        cout << "Transposing the matrix using a tiled approach" << endl;
        cout << "Using a grid size of " << tileGridSize << endl;
        cout << "A tile has size " << tileSize << " and contains " << tileDimension << " elements" << endl;
        printMatrix(matrix, matrixSize);
    }

    for (int tileGridRow = 0; tileGridRow < tileGridSize; tileGridRow ++) {
        for (int tileGridCol = 0; tileGridCol < tileGridSize; tileGridCol ++) {

            // The actual index in the array
            int tileIndex = tileGridRow * tileGridSize * tileDimension + tileGridCol * tileSize;
            int transposedBlockIndex = tileGridCol * tileGridSize * tileDimension + tileGridRow * tileSize;


            for (int tileRow = 0; tileRow < tileSize; tileRow++) {
                for (int tileCol = 0; tileCol < tileSize; tileCol++) {

                    int index = tileIndex + matrixSize * tileRow + tileCol;
                    int transposedIndex = transposedBlockIndex + matrixSize * tileCol + tileRow;

                    transposedMatrix[transposedIndex] = matrix[index];
                }
            }
        }
    }

    if (debug) {
        cout << "Matrix transposed" << endl;
        printMatrix(transposedMatrix, matrixSize);
    }
}

void printMatrix(const MATRIX_TYPE* matrix, int matrixSize) {

    cout << "Matrix [Rows:  " << matrixSize << " | Columns: " << matrixSize << "]: " << endl;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i * matrixSize + j] << " ";
        }
        cout << endl;
    }
}

