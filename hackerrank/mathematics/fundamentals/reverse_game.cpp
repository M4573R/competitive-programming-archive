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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int balls;
        unsigned int index;

        cin >> balls >> index;

        if (index < balls / 2)
        {
            cout << 2 * index + 1;
        }
        else
        {
            cout << 2 * (balls - 1 - index);
        }

        cout << '\n';
    }

    return 0;
}
