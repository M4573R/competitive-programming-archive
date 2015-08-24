#include <iostream>
#include <string>

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
        string bits;
        cin >> bits;

        unsigned int matches {0};

        for (auto bit = bits.cbegin(); bit < bits.cend() - 1; ++bit)
        {
            if (*bit == '0' && *(bit + 1) == '1')
            {
                ++matches;
            }
        }

        cout << matches << '\n';
    }

    return 0;
}
