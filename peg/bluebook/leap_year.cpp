#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool is_leap(unsigned int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int year;
        cin >> year;

        cout << is_leap(year) << '\n';
    }

    return 0;
}
