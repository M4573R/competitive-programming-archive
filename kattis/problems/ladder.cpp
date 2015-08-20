#include <cmath>
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
double to_radians(double degrees)
{
    return pi / 180 * degrees;
}

int main()
{
    use_io_optimizations();

    unsigned int height;
    unsigned int angle;

    cin >> height >> angle;

    cout << ceil(height / sin(to_radians(angle))) << '\n';

    return 0;
}
