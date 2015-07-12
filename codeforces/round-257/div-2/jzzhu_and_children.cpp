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

    unsigned int children;
    unsigned int candies;

    cin >> children >> candies;

    unsigned int maximum {0};
    unsigned int last    {0};

    for (unsigned int i {1}; i <= children; ++i)
    {
        unsigned int needed;
        cin >> needed;

        unsigned int iterations {(needed + candies - 1) / candies};

        if (iterations >= maximum)
        {
            maximum = iterations;
            last    = i;
        }
    }

    cout << last << '\n';

    return 0;
}
