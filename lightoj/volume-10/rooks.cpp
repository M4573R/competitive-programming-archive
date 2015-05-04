#include <algorithm>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned long long count_ways(unsigned int size, unsigned int rooks)
{
    if (rooks > size)
    {
        return 0;
    }

    unsigned long long ways = 1;

    for (unsigned int i = size; i > max(rooks, size - rooks); --i)
    {
        ways *= i;
    }

    for (unsigned int i = 1; i <= min(rooks, size - rooks); ++i)
    {
        ways /= i;
    }

    ways *= ways;

    for (unsigned int i = 1; i <= rooks; ++i)
    {
        ways *= i;
    }

    return ways;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int size;
        unsigned int rooks;

        cin >> size >> rooks;

        cout << "Case " << test << ": " << count_ways(size, rooks) << '\n';
    }

    return 0;
}
