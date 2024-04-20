/**
 * @Author Enea Strambini
 * @brief Library for matrix operations
 */

#ifndef MATRIXLIB_H
#define MATRIXLIB_H

// Define the type of the matrix
#ifndef MATRIX_TYPE
#define MATRIX_TYPE int
#endif

// Define the maximum value for the random number in the matrix, in the range [0, MAX_RANDOM_NUMBER)
#ifndef MAX_RANDOM_NUMBER
#define MAX_RANDOM_NUMBER 100
#endif

/**
 * Method that allocate memory for a matrix, and initialize it with random values
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 * @param generateValue - If true, the matrix will be initialized with random values, otherwise it will be left empty
 * @return the initialized matrix
 */
MATRIX_TYPE* initMatrix(int matrixSize, bool generateValue = true);

/**
 * Method that compute the transpose of a matrix
 * @param matrix - Pointer to the matrix
 * @param transposedMatrix - Pointer to the transposed matrix where the result will be stored
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 * @param debug - If true, the matrix will be printed
 */
void transposeMatrix(const MATRIX_TYPE* matrix, MATRIX_TYPE* transposedMatrix, int matrixSize, bool debug = false);

/**
 * Method that compute the transpose of a matrix using a tiled approach
 * @param matrix - Pointer to the matrix
 * @param transposedMatrix - Pointer to the transposed matrix where the result will be stored
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 * @param tileGridSize - Size of the block grid, the number is an exponent for a power of 2
 * @param debug - If true, the matrix will be printed
 */
void transposeMatrixTiled(
        const MATRIX_TYPE* matrix,
        MATRIX_TYPE* transposedMatrix,
        int matrixSize,
        int tileGridSize,
        bool debug = false
    );

/**
 * Method that neatly prints a matrix
 * @param matrix - Pointer to the matrix
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 */
void printMatrix(const MATRIX_TYPE* matrix, int matrixSize);

#endif
