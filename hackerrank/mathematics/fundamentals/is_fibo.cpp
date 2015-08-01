#include <iostream>
#include <set>

using namespace std;

constexpr unsigned long long max_fibonacci {10e10};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    set<unsigned long long> fibonacci;

    for (unsigned long long a {0}, b {1}; a <= max_fibonacci; )
    {
        fibonacci.insert(a);

        unsigned long long c {a + b};
        a = b;
        b = c;
    }

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned long long number;
        cin >> number;

        cout << (fibonacci.count(number) ? "IsFibo" : "IsNotFibo") << '\n';
    }

    return 0;
}
