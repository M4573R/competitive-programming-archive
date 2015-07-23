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
        unsigned int kids;
        cin >> kids;

        unsigned long long candies_mod_kids {0};

        for (unsigned int i {0}; i < kids; ++i)
        {
            unsigned long long candies;
            cin >> candies;

            candies_mod_kids = (candies_mod_kids + candies % kids) % kids;
        }

        cout << (candies_mod_kids ? "NO" : "YES") << '\n';
    }

    return 0;
}
