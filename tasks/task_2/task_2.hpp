#include <utility>
#include <optional>

using namespace std;

struct Point{
    double x;
    double y;
    Point(double x_, double y_): x(x_), y(y_){}
};

class Line
{
public://std::pair(Point)
    pair<double, double> p; //(tilt factor, free factor)  /y = m*x + b/ (m, b)
    Line(const double x, const double y);
    Line(const pair<double, double>& p_);
    Line(const pair<double, double>& p1, const pair<double, double>& p2);
    pair<double, double> get_equation(const pair<double, double>& p1, const pair<double, double>& p2);
};
namespace Framework//name space 
{
    optional<Point> find_intersection(const Line& line1, const Line& line2);
    optional<Line> find_perpendicular(const Line& line, const Point& p);
};