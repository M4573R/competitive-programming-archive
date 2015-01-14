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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int rows;
        unsigned int columns;

        cin >> rows >> columns;

        cout << (rows / 3) * (columns / 3) << '\n';
    }

    return 0;
}
