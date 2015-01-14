#include <cstdlib>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        int lower;
        int upper;

        cin >> lower >> upper;

        int grade;

        if (lower % 2 != upper % 2)
        {
            grade = (upper - lower + 1) / 2;
        }
        else
        {
            grade = (upper - lower) / 2 - upper;
        }

        cout << abs(grade) % 5 + 2 << '\n';
    }

    return 0;
}
