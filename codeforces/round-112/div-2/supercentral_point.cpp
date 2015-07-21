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
};

bool is_supercentral(const Point& point, const vector<Point>& points)
{
    bool has_left  {false};
    bool has_right {false};
    bool has_upper {false};
    bool has_lower {false};

    for (const auto& other : points)
    {
        if (point.x == other.x && point.y < other.y)
        {
            has_upper = true;
        }

        if (point.x == other.x && point.y > other.y)
        {
            has_lower = true;
        }

        if (point.x < other.x && point.y == other.y)
        {
            has_right = true;
        }

        if (point.x > other.x && point.y == other.y)
        {
            has_left = true;
        }
    }

    return has_left && has_right && has_upper && has_lower;
}

int main()
{
    use_io_optimizations();

    unsigned int points_count;
    cin >> points_count;

    vector<Point> points(points_count);

    for (auto& point : points)
    {
        cin >> point.x >> point.y;
    }

    unsigned int supercentral {0};

    for (const auto& point : points)
    {
        if (is_supercentral(point, points))
        {
            ++supercentral;
        }
    }

    cout << supercentral << '\n';

    return 0;
}
