#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int palindrome_length;
        cin >> palindrome_length;

        if (palindrome_length % 2 == 0)
        {
            cout << palindrome_length;
        }
        else
        {
            cout << palindrome_length - 1;
        }

        cout << '\n';
    }

    return 0;
}
