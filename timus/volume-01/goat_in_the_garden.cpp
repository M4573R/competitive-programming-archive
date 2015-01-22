#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {3.14159265359};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(3);

    double garden_side;
    double cord_length;

    cin >> garden_side >> cord_length;

    double goat_area {pi * cord_length * cord_length};

    if (2 * cord_length <= garden_side)
    {
        cout << goat_area;
    }
    else if (2 * cord_length * cord_length >= garden_side * garden_side)
    {
        cout << garden_side * garden_side;
    }
    else
    {
        double angle {2 * acos(garden_side / (2 * cord_length))};
        double area  {cord_length * cord_length * (angle - sin(angle)) / 2};

        cout << goat_area - 4 * area;
    }

    cout << '\n';

    return 0;
}
