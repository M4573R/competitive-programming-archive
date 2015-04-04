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

    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;

    cin >> a >> b >> c >> d;

    if (a < b && b < c && c < d)
    {
        cout << "Fish Rising";
    }
    else if (a > b && b > c && c > d)
    {
        cout << "Fish Diving";
    }
    else if (a == b && b == c && c == d)
    {
        cout << "Fish At Constant Depth";
    }
    else
    {
        cout << "No Fish";
    }

    cout << '\n';

    return 0;
}
