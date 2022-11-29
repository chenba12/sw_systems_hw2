#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MatrixSize 10

void checkPaths();

int matrix[MatrixSize][MatrixSize];
int infinity = INT_MAX;


void initMatrix() {
    for (size_t i = 0; i < MatrixSize; ++i) {
        for (size_t j = 0; j < MatrixSize; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    checkPaths();
}

void checkPaths() {
    for (size_t k = 0; k < MatrixSize; ++k) {
        for (size_t i = 0; i < MatrixSize; ++i) {
            for (size_t j = 0; j < MatrixSize; ++j) {
                if (i != j) {
                    if (matrix[i][k] != 0 && matrix[k][j] != 0) {
                        matrix[i][j] = (int) fmin(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
    }
}

int isPathAvailable(size_t i, size_t j) {
    if (matrix[i][j] != 0) return 1;
    return 0;
}

int findShortest(size_t i,size_t j) {
    if (matrix[i][j] != 0) return matrix[i][j];
    return -1;
}