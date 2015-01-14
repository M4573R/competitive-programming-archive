#include <cstdlib>
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
        int number;
        cin >> number;

        number = (number * 567 / 9 + 7492) * 235 / 47 - 498;

        cout << abs(number) / 10 % 10 << '\n';
    }

    return 0;
}
