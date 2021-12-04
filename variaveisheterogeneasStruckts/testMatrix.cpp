
#include "testMatrix.h"

void testIdentity() {
    Matrix id = getIdentityMatrix(4);
    for (int i = 0; i < id.rows; ++i) {
        for (int j = 0; j < id.cols; ++j) {
            std::cout
                    << std::setw(3)
                    << std::setfill(' ')
                    << id.elements[i][j]
                    << " ";
        }
        std::cout << std::endl;
    }
}

