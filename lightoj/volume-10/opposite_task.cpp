#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 0; test < test_cases; ++test)
    {
        unsigned int problems;
        cin >> problems;

        if (problems < 10)
        {
            cout << 0 << ' ' << problems << '\n';
        }
        else
        {
            cout << 10 << ' ' << problems - 10 << '\n';
        }
    }

    return 0;
}
