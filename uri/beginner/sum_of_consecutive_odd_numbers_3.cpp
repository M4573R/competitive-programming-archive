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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        int lower_limit;
        int count;

        cin >> lower_limit >> count;

        if (lower_limit % 2 == 0)
        {
            ++lower_limit;
        }

        cout << count * (lower_limit + count - 1) << '\n';
    }

    return 0;
}
