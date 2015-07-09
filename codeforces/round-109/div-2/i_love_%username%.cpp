#include <algorithm>
#include <iostream>

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

    unsigned int contests;
    cin >> contests;

    unsigned int minimum;
    cin >> minimum;

    unsigned int maximum {minimum};
    unsigned int amazing_performances {0};

    for (unsigned int i {1}; i < contests; ++i)
    {
        unsigned int points;
        cin >> points;

        if (points < minimum || points > maximum)
        {
            ++amazing_performances;
        }

        minimum = min(minimum, points);
        maximum = max(maximum, points);
    }

    cout << amazing_performances << '\n';

    return 0;
}
