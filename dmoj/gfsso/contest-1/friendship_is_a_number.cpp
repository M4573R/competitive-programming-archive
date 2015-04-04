#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Programmer
{
    unsigned int id;
    long long friend_points;
};

bool operator>(const Programmer& left, const Programmer& right)
{
    return left.friend_points > right.friend_points;
}

int main()
{
    use_io_optimizations();

    unsigned int programmers_count;
    cin >> programmers_count;

    vector<Programmer> programmers(programmers_count);

    for (unsigned int i {0}; i < programmers_count; ++i)
    {
        programmers[i].id            = i + 1;
        programmers[i].friend_points = 1;

        unsigned int traits;
        cin >> traits;

        for (unsigned int j {0}; j < traits; ++j)
        {
            int trait;
            cin >> trait;

            programmers[i].friend_points *= trait;
        }
    }

    sort(programmers.begin(), programmers.end(), greater<Programmer>());

    cout << programmers[0].id << '\n'
         << programmers[1].id << '\n'
         << programmers[2].id << '\n';

    return 0;
}
