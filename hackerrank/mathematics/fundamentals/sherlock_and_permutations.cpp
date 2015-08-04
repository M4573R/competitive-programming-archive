#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int modulo {1000000007};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<vector<unsigned int>> combinations(2001, vector<unsigned int>(2001));

    for (unsigned int i {0}; i <= 2000; ++i)
    {
        combinations[i][0] = 1;

        for (unsigned int j {1}; j <= i; ++j)
        {
            combinations[i][j] = (combinations[i - 1][j - 1] +
                                  combinations[i - 1][j]) % modulo;
        }
    }

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int zeros;
        unsigned int ones;

        cin >> zeros >> ones;

        cout << combinations[zeros + ones - 1][zeros] << '\n';
    }

    return 0;
}
