#include <algorithm>
#include <iostream>
#include <limits>

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

    int restaurants;
    int time_limit;

    cin >> restaurants >> time_limit;

    int max_joy {numeric_limits<int>::min()};

    for (int i {0}; i < restaurants; ++i)
    {
        int joy;
        int time;

        cin >> joy >> time;

        max_joy = max(max_joy, min(joy, joy - (time - time_limit)));
    }

    cout << max_joy << '\n';

    return 0;
}
