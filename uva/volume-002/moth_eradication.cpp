#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

constexpr double epsilon {1e-9};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

double zero(double number)
{
    return number > -epsilon && number < epsilon;
}

struct Point
{
    double x;
    double y;

    Point() = default;

    Point(double x, double y):
        x(x), y(y)
    { }
};

double distance2(const Point& a, const Point& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double distance(const Point& a, const Point& b)
{
    return sqrt(distance2(a, b));
}

double orientation(const Point& a, const Point& b, const Point& c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

class ByCoordinates
{
public:
    bool operator()(const Point& left, const Point& right)
    {
        return left.x < right.x || (left.x == right.x && left.y < right.y);
    }
};

class ByPolarAngle
{
public:
    ByPolarAngle(const Point& origin):
        origin(origin)
    { }

    bool operator()(const Point& left, const Point& right)
    {
        double relative_to_origin {orientation(origin, left, right)};

        if (zero(relative_to_origin))
        {
            return distance2(origin, left) < distance2(origin, right);
        }

        return relative_to_origin > 0;
    }

private:
    Point origin;
};

vector<Point> convex_hull(vector<Point>& points)
{
    if (points.size() < 2)
    {
        return points;
    }

    Point origin {*min_element(points.begin(), points.end(), ByCoordinates())};
    sort(points.begin(), points.end(), ByPolarAngle(origin));

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < points.size(); ++i)
    {
        while (orientation(*(hull.end() - 2), hull.back(), points[i]) <= 0)
        {
            hull.pop_back();

            if (hull.size() == 1)
            {
                break;
            }
        }

        hull.push_back(points[i]);
    }

    return hull;
}

double perimeter(const vector<Point>& hull)
{
    double perimeter {0};

    for (vector<Point>::size_type i {0}; i < hull.size(); ++i)
    {
        perimeter += distance(hull[i], hull[(i + 1) % hull.size()]);
    }

    return perimeter;
}

int main()
{
    use_io_optimizations();

    cout << fixed;

    for (unsigned int region {1}, traps; cin >> traps && traps != 0; ++region)
    {
        vector<Point> locations(traps);

        for (auto& location : locations)
        {
            cin >> location.x >> location.y;
        }

        vector<Point> hull {convex_hull(locations)};

        cout << "Region #" << region << ":\n";
        cout << setprecision(1);

        for (auto point = hull.rbegin(); point != hull.rend(); ++point)
        {
            cout << '(' << point->x << ',' << point->y << ")-";
        }

        cout << '(' << hull.back().x << ',' << hull.back().y << ')' << '\n';

        cout << "Perimeter length = ";
        cout << setprecision(2) << perimeter(hull) << '\n' << '\n';
    }

    return 0;
}
