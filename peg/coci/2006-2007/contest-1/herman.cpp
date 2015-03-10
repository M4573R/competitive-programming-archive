#include <iomanip>
#include <iostream>

using namespace std;

constexpr double pi {3.141592653589793};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(4);

    unsigned int radius;
    cin >> radius;

    cout << pi * radius * radius << '\n'
         << 2  * radius * radius << '\n';

    return 0;
}
