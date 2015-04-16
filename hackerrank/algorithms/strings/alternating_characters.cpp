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
        string input;
        cin >> input;

        unsigned int deletions {0};

        for (auto symbol = input.cbegin() + 1; symbol != input.cend(); ++symbol)
        {
            if (*(symbol - 1) == *symbol)
            {
                ++deletions;
            }
        }

        cout << deletions << '\n';
    }

    return 0;
}
