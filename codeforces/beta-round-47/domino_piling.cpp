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

    unsigned int width;
    unsigned int height;

    cin >> width >> height;

    cout << width * height / 2 << '\n';

    return 0;
}
