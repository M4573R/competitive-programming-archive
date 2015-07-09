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

    unsigned int available;
    cin >> available;

    unsigned int height {0};
    unsigned int used   {0};

    while (used <= available)
    {
        ++height;
        used += height * (height + 1) / 2;
    }

    cout << height - 1 << '\n';

    return 0;
}
