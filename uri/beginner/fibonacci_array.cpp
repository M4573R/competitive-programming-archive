#include <iostream>
#include <utility>
#include <vector>

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

    vector<long long> fibonacci(61);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (unsigned int i {2}; i <= 60; ++i)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int index;
        cin >> index;

        cout << "Fib(" << index << ") = " << fibonacci[index] << '\n';
    }

    return 0;
}
