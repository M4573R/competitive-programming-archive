#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int reverse(unsigned int number)
{
    unsigned int reversed {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        reversed = reversed * 10 + i % 10;
    }

    return reversed;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int first;
        unsigned int second;

        cin >> first >> second;

        cout << reverse(reverse(first) + reverse(second)) << '\n';
    }

    return 0;
}
