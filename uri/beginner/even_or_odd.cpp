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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        int number;
        cin >> number;

        if (number == 0)
        {
            cout << "NULL\n";
        }
        else
        {
            cout << (number % 2 ? "ODD" : "EVEN")          << ' '
                 << (number < 0 ? "NEGATIVE" : "POSITIVE") << '\n';
        }
    }

    return 0;
}
