#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int grid_dimension;

    while (cin >> grid_dimension && grid_dimension != 0)
    {
        unsigned int squares = 0;

        for (unsigned int i = 1; i <= grid_dimension; ++i)
        {
            squares += (grid_dimension - i + 1) * (grid_dimension - i + 1);
        }

        cout << squares << '\n';
    }

    return 0;
}
