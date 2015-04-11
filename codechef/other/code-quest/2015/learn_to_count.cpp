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
        unsigned int number;
        cin >> number;

        unsigned int trailing_zeroes {0};

        while (!(number & (1 << trailing_zeroes)))
        {
            ++trailing_zeroes;
        }

        cout << trailing_zeroes << '\n';
    }

    return 0;
}
