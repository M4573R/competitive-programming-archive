#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {2 * acos(0)};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int radius;
    unsigned int height;

    cin >> radius >> height;

    cout << pi * radius * radius * height / 3 << '\n';

    return 0;
}
