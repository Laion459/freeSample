#pragma once
const int MAX_POINTS = 15;
struct Point2D {
    double x = 0, y = 0;
};
struct Polygon {
    Point2D vertex[MAX_POINTS];
    int numVertices = 0;
};