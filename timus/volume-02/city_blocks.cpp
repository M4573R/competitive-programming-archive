#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    if (b == 0)
    {
        return a == 0 ? 1 : a;
    }

    for (unsigned int r {a % b}; r > 0; r = a % b)
    {
        a = b;
        b = r;
    }

    return b;
}

int main()
{
    use_io_optimizations();

    unsigned int height;
    unsigned int width;

    cin >> height >> width;

    --height;
    --width;

    cout << height + width - gcd(height, width) << '\n';

    return 0;
}
