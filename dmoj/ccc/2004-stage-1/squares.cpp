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

    unsigned int tiles;
    cin >> tiles;

    unsigned int side {0};

    while (side * side <= tiles)
    {
        ++side;
    }

    cout << "The largest square has side length " << side - 1 << ".\n";

    return 0;
}
