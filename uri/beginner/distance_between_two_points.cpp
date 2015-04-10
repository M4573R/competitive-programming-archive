#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

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

    double first_x;
    double first_y;

    cin >> first_x >> first_y;

    double second_x;
    double second_y;

    cin >> second_x >> second_y;

    cout << sqrt((first_x - second_x) * (first_x - second_x) +
                 (first_y - second_y) * (first_y - second_y))
         << '\n';

    return 0;
}
