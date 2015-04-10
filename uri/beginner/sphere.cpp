#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi = 3.14159;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(3);

    double radius;
    cin >> radius;

    cout << "VOLUME = " << 4.0 / 3.0 * pi * radius * radius * radius << '\n';

    return 0;
}
