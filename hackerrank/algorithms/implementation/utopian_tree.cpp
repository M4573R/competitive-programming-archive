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

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int cycles;
        cin >> cycles;

        unsigned int height {1};

        for (unsigned int cycle {0}; cycle < cycles; ++cycle)
        {
            height += (cycle % 2 == 0 ? height : 1);
        }

        cout << height << '\n';
    }

    return 0;
}
