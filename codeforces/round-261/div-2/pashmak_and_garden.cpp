#include <cstdlib>
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

    int x1;
    int y1;
    int x2;
    int y2;

    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
    {
        int side {abs(y1 - y2)};

        cout << x1 + side << ' ' << y1 << ' '
             << x2 + side << ' ' << y2 << '\n';
    }
    else if (y1 == y2)
    {
        int side {abs(x1 - x2)};

        cout << x1 << ' ' << y1 + side << ' '
             << x2 << ' ' << y2 + side << '\n';
    }
    else if (abs(x1 - x2) == abs(y1 - y2))
    {
        cout << x1 << ' ' << y2 << ' '
             << x2 << ' ' << y1 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}
