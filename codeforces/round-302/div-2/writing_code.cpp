#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int plans_count(unsigned int programmers,
                         unsigned int lines,
                         unsigned int max_bugs,
                         unsigned int modulo)
{
    vector<vector<unsigned int>> plans(
        lines + 1,
        vector<unsigned int>(max_bugs + 1)
    );

    plans[0][0] = 1 % modulo;

    for (unsigned int i {0}; i < programmers; ++i)
    {
        unsigned int bugs;
        cin >> bugs;

        for (unsigned int x {0}; x < lines; ++x)
        {
            for (unsigned int y {bugs}; y <= max_bugs; ++y)
            {
                plans[x + 1][y] += plans[x][y - bugs];
                plans[x + 1][y] %= modulo;
            }
        }
    }

    unsigned int total_plans {0};

    for (unsigned int i {0}; i <= max_bugs; ++i)
    {
        total_plans = (total_plans + plans[lines][i]) % modulo;
    }

    return total_plans;
}

int main()
{
    use_io_optimizations();

    unsigned int programmers;
    unsigned int lines;
    unsigned int max_bugs;
    unsigned int modulo;

    cin >> programmers >> lines >> max_bugs >> modulo;

    cout << plans_count(programmers, lines, max_bugs, modulo) << '\n';

    return 0;
}
