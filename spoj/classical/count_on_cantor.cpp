#include <iostream>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int find_diagonal(unsigned int term)
{
    unsigned int diagonal {0};

    for (unsigned int i {0}; i < term; i += diagonal)
    {
        ++diagonal;
    }

    return diagonal;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int term;
        cin >> term;

        unsigned int diagonal {find_diagonal(term)};
        unsigned int position {term - diagonal * (diagonal - 1) / 2};

        unsigned int numerator   {position};
        unsigned int denominator {diagonal - position + 1};

        if (diagonal % 2)
        {
            swap(numerator, denominator);
        }

        cout << "TERM " << term << " IS "
             << numerator << '/' << denominator << '\n';
    }

    return 0;
}
