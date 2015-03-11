#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const unsigned int mod = 5741;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int lucky_tickets(unsigned int digits, unsigned int sum)
{
    vector< vector<unsigned int> > subtasks(digits,
                                            vector<unsigned int>(sum + 1));

    for (unsigned int i {0}; i <= min(9u, sum); ++i)
    {
        subtasks[0][i] = 1;
    }

    for (unsigned int i {1}; i < digits; ++i)
    {
        for (unsigned int j {0}; j <= sum; ++j)
        {
            for (unsigned int digit {0}; digit <= 9; ++digit)
            {
                if (j >= digit)
                {
                    subtasks[i][j] += subtasks[i - 1][j - digit];
                    subtasks[i][j] %= mod;
                }
            }
        }
    }
    return (subtasks[digits - 1][sum] * subtasks[digits - 1][sum]) % mod;
}

int main()
{
    use_io_optimizations();

    unsigned int digits;
    unsigned int sum;

    cin >> digits >> sum;

    if (sum % 2 != 0)
    {
        cout << 0;
    }
    else
    {
        cout << lucky_tickets(digits, sum / 2);
    }

    cout << '\n';

    return 0;
}
