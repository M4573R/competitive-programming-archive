#include <iostream>
#include <vector>

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

    unsigned int programmers;
    unsigned int lines;
    unsigned int max_bugs;
    unsigned int modulo;

    cin >> programmers >> lines >> max_bugs >> modulo;

    vector<vector<unsigned int>> plans(
        lines + 1,
        vector<unsigned int>(max_bugs + 1)
    );

    plans[0][0] = 1 % modulo;

    for (unsigned int k {0}; k < programmers; ++k)
    {
        unsigned int bugs;
        cin >> bugs;

        for (unsigned int i {0}; i < lines; ++i)
        {
            for (unsigned int j {0}; j <= max_bugs - bugs; ++j)
            {
                plans[i + 1][j + bugs] = (plans[i + 1][j + bugs] + plans[i][j]) % modulo;
            }
        }
    }

    unsigned int total_plans {0};

    for (unsigned int i {0}; i <= max_bugs; ++i)
    {
        total_plans = (total_plans + plans[lines][i]) % modulo;
    }

    cout << total_plans << '\n';


    return 0;
}
