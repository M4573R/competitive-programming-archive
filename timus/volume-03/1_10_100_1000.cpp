#include <cmath>
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
        long long position;
        cin >> position;

        long long root = (-1 + sqrtl(8 * position - 7)) / 2;

        cout << (root * (root + 1) == 2 * (position - 1));

        if (i < test_cases - 1)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
