#include <algorithm>
#include <cmath>
#include <iomanip>
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
    int x;
    int y;

    unsigned int id;

    Point() = default;

    Point(int x, int y, unsigned int id = 0):
        x(x), y(y), id(id)
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

int oriented_area(const Point& a, const Point& b, const Point& c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int orientation(const Point& a, const Point& b, const Point& c)
{
    return oriented_area(a, b, c);
}

class ByPolarAngle
{
public:
    ByPolarAngle(const Point& origin):
        origin(origin)
    { }

    bool operator()(const Point& left, const Point& right)
    {
        int relative_to_origin = orientation(origin, left, right);

        if (relative_to_origin == 0)
        {
            return distance2(origin, left) <= distance2(origin, right);
        }

        return relative_to_origin > 0;
    }

private:
    Point origin;
};

class ByCoordinates
{
public:
    bool operator()(const Point& left, const Point& right)
    {
        return left.y < right.y || (left.y == right.y && left.x < right.x);
    }
};

vector<Point> convex_hull(vector<Point>& points)
{
    if (points.size() < 2)
    {
        return points;
    }

    Point origin = *min_element(points.begin(), points.end(), ByCoordinates());
    sort(points.begin(), points.end(), ByPolarAngle(origin));

    vector<Point> hull;
    hull.push_back(origin);
    hull.push_back(points[1]);

    for (vector<Point>::size_type i = 2; i < points.size(); ++i)
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

double hull_length(const vector<Point>& hull)
{
    double fence_length {0};

    for (vector<Point>::size_type i {0}; i < hull.size(); ++i)
    {
        fence_length += distance(hull[i], hull[(i + 1) % hull.size()]);
    }

    return fence_length;
}

void print_hull(const vector<Point>& hull)
{
    for (vector<Point>::size_type i {0}; i < hull.size(); ++i)
    {
        cout << hull[i].id;

        if (i < hull.size() - 1)
        {
            cout << ' ';
        }
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int sheep;
        cin >> sheep;

        vector<Point> positions(sheep);

        for (unsigned int i {0}; i < sheep; ++i)
        {
            int x;
            int y;

            cin >> x >> y;

            positions[i] = {x, y, i + 1};
        }

        vector<Point> hull {convex_hull(positions)};

        cout << hull_length(hull) << '\n';
        print_hull(hull);
        cout << '\n';
    }

    return 0;
}
