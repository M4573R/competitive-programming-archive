#include <algorithm>
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

    int max_x;
    int max_y;

    cin >> max_x >> max_y;

    for (int x {0}, y {0}, delta_x, delta_y;
         cin >> delta_x >> delta_y && !(delta_x == 0 && delta_y == 0); )
    {
        x = min(max(x + delta_x, 0), max_x);
        y = min(max(y + delta_y, 0), max_y);

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
