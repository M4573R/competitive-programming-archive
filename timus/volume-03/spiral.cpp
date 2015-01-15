#include <algorithm>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int height;
    unsigned int width;

    cin >> height >> width;

    cout << 2 * (min(height, width) - 1) + (height > width) << '\n';

    return 0;
}
