#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr unsigned int gravity {10};
constexpr double       pi      {3.1415926535};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
double to_radians(unsigned int in_degrees)
{
    return in_degrees * pi / 180;
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int speed;
    unsigned int angle;
    double factor;

    cin >> speed >> angle >> factor;

    double first_term {speed * speed * sin(to_radians(2 * angle)) / gravity};

    cout << first_term / (1 - 1 / factor) << '\n';

    return 0;
}
