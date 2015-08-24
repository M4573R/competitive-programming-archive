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
        unsigned int elephants;
        unsigned int candies;

        cin >> elephants >> candies;

        unsigned int needed_candies {0};

        for (unsigned int i {0}; i < elephants; ++i)
        {
            unsigned int lower_limit;
            cin >> lower_limit;

            needed_candies += lower_limit;
        }

        cout << (needed_candies <= candies ? "Yes" : "No") << '\n';
    }

    return 0;
}
