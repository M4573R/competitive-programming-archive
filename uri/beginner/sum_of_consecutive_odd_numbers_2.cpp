#include <iostream>
#include <utility>

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
        int lower;
        int upper;

        cin >> lower >> upper;

        if (lower > upper)
        {
            swap(lower, upper);
        }

        if (lower % 2)
        {
            ++lower;
        }

        int sum {0};

        for (int i {lower + 1}; i < upper; i += 2)
        {
            sum += i;
        }

        cout << sum << '\n';
    }

    return 0;
}
