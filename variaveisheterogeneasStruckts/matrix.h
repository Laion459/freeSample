#pragma once
#include <cstring>
#include <iostream>
#include <iomanip>
#include "testMatrix.h"
#include "testPolygon.h"

const int MAX_MATRIX_ROWS = 10;
const int MAX_MATRIX_COLS = 10;

struct Matrix {
    int elements[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];
    int rows = -1;
    int cols = -1;
};

Matrix getIdentityMatrix(int n);