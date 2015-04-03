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

    unsigned int available_time;
    cin >> available_time;

    unsigned int chores;
    cin >> chores;

    vector<unsigned int> chore_times(chores);

    for (auto& time : chore_times)
    {
        cin >> time;
    }

    sort(chore_times.begin(), chore_times.end());

    unsigned int done_chores {0};
    unsigned int spent_time  {0};

    for (auto chore_time : chore_times)
    {
        if (spent_time + chore_time <= available_time)
        {
            ++done_chores;
            spent_time += chore_time;
        }
    }

    cout << done_chores << '\n';

    return 0;
}
