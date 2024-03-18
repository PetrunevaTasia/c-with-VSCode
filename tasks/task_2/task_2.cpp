#include "task_2.h"

// Point::Point() : x(0), y(0) {}
// Point::Point(double x_, double y_) : x(x_), y(y_) {}

Line::Line(const double x, const double y) : p(Point(x, y)) {}
Line::Line(const Point& p_) : p(p_) {}
Line::Line(const Point& p1, const Point& p2) : p(get_equation(p1, p2)) {}
Point Line::get_equation(const Point& p1, const Point& p2) {
    double m = (p2.y - p1.y) / (p2.x - p1.x);
    double b = p1.y - m * p1.x;
    return Point(m, b);
}
//std::optional
Point Framework::find_intersection(const Line& line1, const Line& line2) {// y = ax + b, y = cx + d 
    double y = (line1.p.x * line2.p.y - line2.p.x * line1.p.y) / (line1.p.x - line2.p.x); //can be /zero
    double x = (line2.p.y - line1.p.y) / (line1.p.x - line2.p.x);
    return Point(x, y);
}
Line Framework::find_perpendicular(const Line& line, const Point& p) {//y = ax + b / y = -(1/a) *(x - x1) + y1 
    double k = (-1 / line.p.x);
    double b = -k * p.x + p.y;
    return Line(k, b);
}