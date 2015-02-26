#include <iomanip>
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

    cout << fixed << setprecision(12);

    unsigned int people;
    double probability;
    unsigned int seconds;

    cin >> people >> probability >> seconds;

    vector<vector<double>> subtasks(seconds + 1, vector<double>(people + 1));
    subtasks[0][0] = 1;

    for (unsigned int i {1}; i <= seconds; ++i)
    {
        for (unsigned int j {0}; j < people; ++j)
        {
            subtasks[i][j]     += subtasks[i - 1][j] * (1 - probability);
            subtasks[i][j + 1] += subtasks[i - 1][j] * probability;
        }

        subtasks[i][people] += subtasks[i - 1][people];
    }

    double expected_people {0};

    for (unsigned int i {1}; i <= people; ++i)
    {
        expected_people += subtasks[seconds][i] * i;
    }

    cout << expected_people << '\n';

    return 0;
}
