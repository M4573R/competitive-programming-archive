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

    unsigned int width;
    unsigned int length;
    unsigned int tile_size;

    cin >> width >> length >> tile_size;

    cout << (width / tile_size) * (length / tile_size) << '\n';

    return 0;
}
