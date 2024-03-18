// class Point//struct
// {
// public:
//     double x;
//     double y;
//     Point();
//     Point(double x_, double y_);
// };
struct Point{
    double x;
    double y;
    Point(double x_, double y_) { x = x_; y = y_; }
};

class Line
{
public://std::pair(Point)
    Point p; //(tilt factor, free factor)  /y = m*x + b/ (m, b)
    Line(const double x, const double y);
    Line(const Point& p_);
    Line(const Point& p1, const Point& p2);
    Point get_equation(const Point& p1, const Point& p2);
};
class Framework//name space 
{
public:
    Point find_intersection(const Line& line1, const Line& line2);
    Line find_perpendicular(const Line& line, const Point& p);
};