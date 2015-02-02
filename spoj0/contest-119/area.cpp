#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const double eps = 1e-12;

struct Point
{
    double x, y;

    Point(double x, double y):
        x(x), y(y)
    { }
};

struct Line
{
    double a, b, c;
};

bool zero(double d)
{
    return d > -eps && d < eps;
}

bool parallel(const Line& l1, const Line& l2)
{
    return zero(l1.a * l2.b - l1.b * l2.a);
}

Point intersect(const Line& l1, const Line& l2)
{
    double denom = l1.a * l2.b - l1.b * l2.a;
    return Point((l2.c * l1.b - l2.b * l1.c) / denom,
                 (l1.c * l2.a - l1.a * l2.c) / denom);
}

double oriented_area(const Point& a, const Point& b, const Point& c)
{
    return (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) * 0.5;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while (t--) {
        Line l1, l2, l3;
        cin >> l1.a >> l1.b >> l1.c >> l2.a >> l2.b >> l2.c >> l3.a >> l3.b >> l3.c;
        if (parallel(l1, l2) || parallel(l1, l3) || parallel(l2, l3)) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        Point x1 = intersect(l1, l2);
        Point x2 = intersect(l1, l3);
        Point x3 = intersect(l2, l3);
        cout << fabs(oriented_area(x1, x2, x3)) << '\n';
    }

    return 0;
}
