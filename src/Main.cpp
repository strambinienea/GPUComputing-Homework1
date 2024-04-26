#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <MatrixLib.h>
using namespace std;
using namespace std::chrono;

/**
 * Method used to calculate the effective bandwidth of the transpose operation
 * @param iterations - Number of iterations to calculate the average execution time
 * @param matrixSize - Size of the matrix
 * @param tiledApproach - Flag to use the tiled approach
 * @param tileGridSize - Size of the grid for the tiled approach
 */
void calculateEffectiveBandwidth(
        const int iterations,
        const int matrixSize,
        const bool tiledApproach = false,
        const int tileGridSize = 2
) {

    MATRIX_TYPE* matrix = nullptr;
    MATRIX_TYPE* transposedMatrix = nullptr;

    // Initialize both matrices
    matrix = initMatrix(matrixSize);
    transposedMatrix = initMatrix(matrixSize, false);

    // Array that contains all the execution times, will be used to calculate the mean value and exclude the outliers
    //
    auto execTimes = (double*) malloc(iterations * sizeof(clock_t));

    if (tiledApproach) {

        cout << "Calculating the effective bandwidth using the tiled approach" << endl;
        for (int i = 0; i < iterations; i++) {

            // Save the start time to calculate the execution time
            auto start = high_resolution_clock::now();
            transposeMatrixTiled(matrix, transposedMatrix, matrixSize, tileGridSize, false);
            auto end = high_resolution_clock::now();

            // calculate the execution time and save it in an array to be processed later
            execTimes[i] = std::chrono::duration<double, std::milli>(end - start).count();
        }
    } else {

        cout << "Calculating the effective bandwidth using the naive approach" << endl;
        for (int i = 0; i < iterations; i++) {

            // Save the start time to calculate the execution time
            auto start = high_resolution_clock::now();
            transposeMatrix(matrix, transposedMatrix, matrixSize, false);
            auto end = high_resolution_clock::now();

            // calculate the execution time and save it in an array to be processed later
            double executionTime = std::chrono::duration<double, std::milli>(end - start).count();
            execTimes[i] = executionTime;
        }
    }

    // Sort the array of execution times, only consider the first 90% of the values
    // This is done to exclude the outliers, only keep values in the 90th percentile
    sort(execTimes, execTimes + iterations);
    int percentile = (int) (iterations * 0.9);
    double average = 0;
    for (int i = 0; i < percentile; i++) { average += execTimes[i]; }
    average = average / percentile;

    cout << "Average execution time: " << average << " ms" << endl;
    cout << "Minimum execution time: " << execTimes[0] << " ms" << endl;
    cout << "Maximum execution time: " << execTimes[percentile - 1] << " ms" << endl;

    // Calculate the effective bandwidth
    double effectiveBandwidth = (2 * matrixSize * matrixSize * sizeof(MATRIX_TYPE)) / (average * 1000);
    cout << "Effective bandwidth: " << effectiveBandwidth << " MB/s" << endl;

    free(matrix);
    free(transposedMatrix);
    free(execTimes);
};

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

    // Default grid size for the tiled approach
    int gridSize = 8;
    if (argc > 2) {
        gridSize = atoi(argv[2]);
    }

    // TILED APPROACH
    calculateEffectiveBandwidth(1000, matrixSize, true, gridSize);
    // NAIVE APPROACH
    calculateEffectiveBandwidth(1000, matrixSize);

    return 0;
}


