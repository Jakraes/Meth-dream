#include "point.h"

Point point(int x, int y) {
    return (Point) {x, y};
}

Point point_add(Point a, Point b) {
    return point(a.x + b.x, a.y + b.y);
}

Point point_sub(Point a, Point b) {
    return point(a.x - b.x, a.y - b.y);
}

bool point_eq(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}