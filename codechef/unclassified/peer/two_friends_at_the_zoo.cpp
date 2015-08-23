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
        unsigned long long factor;
        unsigned long long multiple;

        cin >> factor >> multiple;

        cout << (multiple % factor == 0 ? "CORRECT" : "WRONG") << '\n';
    }

    return 0;
}
