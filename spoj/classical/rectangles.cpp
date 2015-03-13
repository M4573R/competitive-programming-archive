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

    unsigned int squares;
    cin >> squares;

    unsigned long long rectangles {0};

    for (unsigned int i {1}; i * i <= squares; ++i)
    {
        rectangles += squares / i - (i - 1);
    }

    cout << rectangles << '\n';

    return 0;
}
