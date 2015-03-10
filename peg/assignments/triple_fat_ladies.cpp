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
        unsigned long long number;
        cin >> number;

        for (number += 1; number * number * number % 1000 != 888; ++number)
        { }

        cout << number << '\n';
    }

    return 0;
}
