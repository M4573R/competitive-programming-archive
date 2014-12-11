#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int precision {2};

constexpr double pi {3.14159265358};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Point
{
    double x;
    double y;

    Point(double x=0, double y=0):
        x(x), y(y)
    { }

    double distance(const Point& other)
    {
        return sqrt((x - other.x) * (x - other.x) +
                    (y - other.y) * (y - other.y));
    }
};

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(precision);

    unsigned int nails_count;
    cin >> nails_count;

    double radius;
    cin >> radius;

    vector<Point> nails_positions(nails_count);

    for (auto& position : nails_positions)
    {
        cin >> position.x >> position.y;
    }

    double nail_circumference {2 * pi * radius};
    double rope_length        {nail_circumference};

    for (unsigned int i {0}; i < nails_count; ++i)
    {
        rope_length += nails_positions[i].distance(
            nails_positions[(i + 1) % nails_count]
        );
    }

    cout << rope_length << '\n';

    return 0;
}
