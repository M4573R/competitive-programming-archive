#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {acos(-1)};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
double to_degrees(double radians)
{
    return 180 / pi * radians;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int width;
    unsigned int height;
    unsigned int seconds;
    unsigned int vertical;
    unsigned int horizontal;

    while (cin >> width >> height >> seconds >> vertical >> horizontal &&
           (width || height || seconds || vertical || horizontal))
    {
        unsigned long long x_offset {vertical * width};
        unsigned long long y_offset {horizontal * height};

        double distance {sqrt(x_offset * x_offset + y_offset * y_offset)};

        cout << to_degrees(acos(x_offset / distance)) << ' '
             << distance / seconds                    << '\n';
    }

    return 0;
}
