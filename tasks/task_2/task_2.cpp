#include "task_2.hpp"

Line::Line(const double x, const double y) : p(pair<double, double>(x, y)) {}
Line::Line(const pair<double, double>& p_) : p(p_) {}
Line::Line(const pair<double, double>& p1, const pair<double, double>& p2) : p(get_equation(p1, p2)) {}
pair<double, double> Line::get_equation(const pair<double, double>& p1, const pair<double, double>& p2) {
    double m = (p2.second - p1.second) / (p2.first - p1.first);
    double b = p1.second - m * p1.first;
    return pair<double, double>(m , b);
}
//std::optional
optional<Point> Framework::find_intersection(const Line& line1, const Line& line2) {// y = ax + b, y = cx + d 
    if ((line1.p.first - line2.p.first) == 0){
        return nullopt;
    }
    double y = (line1.p.first * line2.p.second - line2.p.first * line1.p.second) / (line1.p.first - line2.p.first); //can be /zero
    double x = (line2.p.second - line1.p.second) / (line1.p.first - line2.p.first);
    return optional<Point>{Point(x, y)};
}
optional<Line> Framework::find_perpendicular(const Line& line, const Point& p) {//y = ax + b / y = -(1/a) *(x - x1) + y1 
    if (line.p.first == 0){
        return nullopt;
    }
    double k = (-1 / line.p.first);
    double b = -k * p.x + p.y;
    return optional<Line>{Line(k, b)};
}