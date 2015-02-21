#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double epsilon = 1e-12;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Point
{
    double x;
    double y;

    Point(double x = 0, double y = 0):
        x(x), y(y)
    { }
};

struct Line
{
    long long a;
    long long b;
    long long c;
};

bool are_parallel(const Line& first, const Line& second)
{
    return first.a * second.b - first.b * second.a == 0;
}

Point intersection(const Line& first, const Line& second)
{
    double denominator = first.a * second.b - first.b * second.a;

    return Point((second.c * first.b  - second.b * first.c)  / denominator,
                 (first.c  * second.a - first.a  * second.c) / denominator);
}

double oriented_area(const Point& a, const Point& b, const Point& c)
{
    return (a.x * b.y + b.x * c.y + c.x * a.y -
            a.y * b.x - b.y * c.x - c.y * a.x) * 0.5;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(12);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        Line ab;
        Line ac;
        Line bc;

        cin >> ab.a >> ab.b >> ab.c
            >> ac.a >> ac.b >> ac.c
            >> bc.a >> bc.b >> bc.c;

        if (are_parallel(ab, ac) || are_parallel(ab, bc) || are_parallel(ac, bc))
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        Point a = intersection(ab, ac);
        Point b = intersection(ab, bc);
        Point c = intersection(ac, bc);

        cout << fabs(oriented_area(a, b, c)) << '\n';
    }

    return 0;
}
