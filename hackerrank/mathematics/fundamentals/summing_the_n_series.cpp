#include <iostream>

using namespace std;

constexpr unsigned int modulo {1000000007};

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

        cout << (number % modulo) * (number % modulo) % modulo << '\n';
    }

    return 0;
}
