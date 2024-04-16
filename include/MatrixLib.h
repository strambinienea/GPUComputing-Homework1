/**
 * @Author Enea Strambini
 * Library for matrix operations
 */

#ifndef MATRIXLIB_H
#define MATRIXLIB_H

// Define the type of the matrix
#ifndef MATRIX_TYPE
#define MATRIX_TYPE int
#endif

// Define the maximum value for the random number in the matrix
#ifndef MAX_RANDOM_NUMBER
#define MAX_RANDOM_NUMBER 100
#endif

/**
 * Method that allocate memory for a matrix, and initialize it with random values
 * @param matrix - Pointer to the matrix
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 * @return the initialized matrix
 */
MATRIX_TYPE* initMatrix(MATRIX_TYPE* matrix, int matrixSize);

/**
 * Method that calculate the transpose of a matrix
 * @param matrix - Pointer to the matrix
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 * @return the transposed matrix
 */
MATRIX_TYPE* transposeMatrix(MATRIX_TYPE* matrix, int matrixSize);

/**
 * Method that neatly prints a matrix
 * @param matrix - Pointer to the matrix
 * @param matrixSize - Size of the matrix, the matrix has the same number of rows and columns
 */
void printMatrix(MATRIX_TYPE* matrix, int matrixSize);

#endif
