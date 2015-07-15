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

    unsigned int rectangles;
    cin >> rectangles;

    unsigned int sum {0};

    for (unsigned int i {0}; i < rectangles; ++i)
    {
        unsigned int ax;
        unsigned int ay;
        unsigned int bx;
        unsigned int by;

        cin >> ax >> ay >> bx >> by;

        sum += (bx - ax + 1) * (by - ay + 1);
    }

    cout << sum << '\n';

    return 0;
}
