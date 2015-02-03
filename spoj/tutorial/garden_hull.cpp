#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Point
{
    long long x;
    long long y;

    Point(long long x = 0, long long y = 0):
        x(x), y(y)
    { }
};

double distance2(const Point& from, const Point& to)
{
    return ((from.x - to.x) * (from.x - to.x) +
            (from.y - to.y) * (from.y - to.y));
}

double distance(const Point& from, const Point& to)
{
    return sqrt(distance2(from, to));
}

long long orientation(const Point& a, const Point& b, const Point& c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

struct ByCoordinates
{
    bool operator()(const Point& left, const Point& right)
    {
        return left.y < right.y || (left.y == right.y && left.x < right.x);
    }
};

struct ByPolarAngle
{
    Point origin;

    ByPolarAngle(const Point& origin):
        origin(origin)
    { }

    bool operator()(const Point& left, const Point& right)
    {
        long long relative_to_origin {orientation(origin, left, right)};

        if (relative_to_origin == 0)
        {
            return distance2(origin, left) <= distance2(origin, right);
        }

        return relative_to_origin > 0;
    }
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

    for (vector<Point>::size_type i {2}; i < points.size(); ++i)
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

int main()
{
    use_io_optimizations();

    unsigned int trees;
    cin >> trees;

    vector<Point> positions(trees);

    for (auto& position : positions)
    {
        cin >> position.x >> position.y;
    }

    double net_length  {0};
    vector<Point> hull {convex_hull(positions)};

    for (vector<Point>::size_type i {0}; i < hull.size(); ++i)
    {
        net_length += distance(hull[i], hull[(i + 1) % hull.size()]);
    }

    cout << static_cast<unsigned long long>(net_length) << '\n';

    return 0;
}
