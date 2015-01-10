#include <cstdlib>
#include <iostream>
#include <string>

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

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string letter;
        cin >> letter;

        unsigned int operations {0};

        for (string::size_type i {0}; i < letter.size() / 2; ++i)
        {
            operations += abs(letter[i] - letter[letter.size() - 1 - i]);
        }

        cout << operations << '\n';
    }

    return 0;
}
