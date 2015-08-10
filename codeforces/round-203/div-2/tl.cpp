#include <algorithm>
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

    unsigned int correct_solutions;
    unsigned int wrong_solutions;

    cin >> correct_solutions >> wrong_solutions;

    vector<unsigned int> correct_times(correct_solutions);

    for (auto& time : correct_times)
    {
        cin >> time;
    }

    vector<unsigned int> wrong_times(wrong_solutions);

    for (auto& time : wrong_times)
    {
        cin >> time;
    }

    unsigned int time_limit {
        max(*min_element(correct_times.cbegin(), correct_times.cend()) * 2,
            *max_element(correct_times.cbegin(), correct_times.cend()))
    };

    if (time_limit >= *min_element(wrong_times.cbegin(), wrong_times.cend()))
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << time_limit << '\n';
    }

    return 0;
}
