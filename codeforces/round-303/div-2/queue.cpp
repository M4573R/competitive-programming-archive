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

    unsigned int people;
    cin >> people;

    vector<unsigned int> times(people);

    for (auto& time : times)
    {
        cin >> time;
    }

    sort(times.begin(), times.end());

    unsigned int       satisfied    {0};
    unsigned long long elapsed_time {0};

    for (auto time : times)
    {
        if (elapsed_time <= time)
        {
            ++satisfied;
            elapsed_time += time;
        }
    }

    cout << satisfied << '\n';

    return 0;
}
