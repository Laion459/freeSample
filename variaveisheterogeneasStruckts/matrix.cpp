
#include "matrix.h"
Matrix getIdentityMatrix(int n) {
    Matrix identity;
    identity.rows = n;
    identity.cols = n;
    int sizeInBytes = MAX_MATRIX_ROWS * MAX_MATRIX_COLS * sizeof(int);
    memset(identity.elements, 0, sizeInBytes);
    for (int i = 0; i < identity.rows; ++i) {
        identity.elements[i][i] = 1;
    }
    return identity;
}
