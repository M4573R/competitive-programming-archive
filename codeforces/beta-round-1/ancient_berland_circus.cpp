#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr double pi        = 3.14159265359;
constexpr double epsilon   = 1e-4;
constexpr double precision = 6;

double gcd(double a, double b)
{
    while (fabs(a) > epsilon && fabs(b) > epsilon)
    {
        if (a > b)
        {
            a -= floor(a / b) * b;
        }
        else
        {
            b -= floor(b / a) * a;
        }
    }

    return a + b;
}


int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(precision);

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    double alpha {acos((b * b + c * c - a * a) / (2 * b * c))};
    double beta  {acos((a * a + c * c - b * b) / (2 * a * c))};
    double gama  {acos((a * a + b * b - c * c) / (2 * a * b))};

    double area   {b * c * sin(alpha) / 2};
    double radius {a * b * c / (4 * area)};

    double vertices {pi / gcd(gcd(alpha, beta), gama)};

    cout << vertices * (radius * radius * sin(2 * pi / vertices) / 2) << '\n';

    return 0;
}
