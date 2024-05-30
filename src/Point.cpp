#include "Point.h"

Point Point::operator+(Point &other) { 
    return Point(x + other.x, y + other.y); 
}

Point Point::operator-(Point &other) { 
    return Point(x - other.x, y - other.y); 
}