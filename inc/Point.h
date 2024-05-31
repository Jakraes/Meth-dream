#ifndef POINT_H
#define POINT_H

#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

Point point(int x, int y);
Point point_add(Point a, Point b);
Point point_sub(Point a, Point b);
bool point_eq(Point a, Point b);

#endif