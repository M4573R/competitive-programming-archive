#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int modulo    {1000000007};
constexpr unsigned int max_score {2000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<vector<unsigned int>> compute_stressfree()
{
    vector<vector<unsigned int>> stressfree(
        max_score + 1, vector<unsigned int>(max_score + 1)
    );

    for (unsigned int i {0}; i <= max_score; ++i)
    {
        stressfree[i][0] = 1;
    }

    for (unsigned int i {1}; i <= max_score; ++i)
    {
        for (unsigned int j {1}; j < i; ++j)
        {
            stressfree[i][j] = (stressfree[i][j - 1] +
                                stressfree[i - 1][j]) % modulo;
        }
    }

    return stressfree;
}

vector<vector<unsigned int>> compute_stressfull()
{
    vector<vector<unsigned int>> stressfull(
        max_score + 1, vector<unsigned int>(max_score + 1)
    );

    for (unsigned int i {0}; i <= max_score; ++i)
    {
        stressfull[0][i] = 1;
    }

    for (unsigned int j {1}; j <= max_score; ++j)
    {
        for (unsigned int i {1}; i <= j; ++i)
        {
            stressfull[i][j] = (stressfull[i - 1][j] +
                                stressfull[i][j - 1]) % modulo;
        }
    }

    return stressfull;
}

int main()
{
    use_io_optimizations();

    vector<vector<unsigned int>> stressfree {compute_stressfree()};
    vector<vector<unsigned int>> stressfull {compute_stressfull()};

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        char dash;

        unsigned int my_score;
        unsigned int opponent_score;

        cin >> my_score >> dash >> opponent_score;

        cout << "Case #" << test << ": ";

        cout << stressfree[my_score][opponent_score]       << ' '
             << stressfull[opponent_score][opponent_score] << '\n';
    }

    return 0;
}
