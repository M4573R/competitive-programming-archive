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

    unsigned int panels;

    unsigned int width;
    unsigned int height;

    cin >> panels >> width >> height;

    cout << 2 * panels * width * height << '\n';

    return 0;
}
