
#include "testPolygon.h"

void testTriangulo(){
    Point2D a, b, c;
    Polygon triangle;
    a.x = 0;
    a.y = 0;
    b.x = 10;
    b.y = 10;
    c.x = 0;
    c.y = 20;
    triangle.vertex[0] = a;
    triangle.vertex[1] = b;
    triangle.vertex[2] = c;
    triangle.numVertices = 3;
    std::cout << triangle.vertex[0].x << std::endl;
    std::cout << triangle.vertex[1].x << std::endl;
    std::cout << triangle.vertex[2].x << std::endl;
    std::cout << triangle.vertex[0].y << std::endl;
}

