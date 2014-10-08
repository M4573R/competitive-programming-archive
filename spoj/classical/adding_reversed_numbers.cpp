#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int reverse_integer(unsigned int n)
{
    unsigned int reversed = 0;

    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return reversed;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int first;
        unsigned int second;

        cin >> first >> second;

        cout << reverse_integer(reverse_integer(first) +
                                reverse_integer(second))
             << '\n';
    }

    return 0;
}
