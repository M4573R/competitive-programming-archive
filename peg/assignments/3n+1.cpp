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

    unsigned int number;
    cin >> number;

    unsigned int steps {0};

    for (unsigned int i {number}; i != 1; ++steps)
    {
        if (i % 2 == 0)
        {
            i /= 2;
        }
        else
        {
            i = 3 * i + 1;
        }
    }

    cout << steps << '\n';

    return 0;
}
