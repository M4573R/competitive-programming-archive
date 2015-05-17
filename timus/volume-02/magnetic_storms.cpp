#include <iostream>
#include <queue>

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

    unsigned int interval;
    cin >> interval;

    queue<unsigned int> measurements;
    deque<unsigned int> highest;

    for (int measurement; cin >> measurement && measurement != -1; )
    {
        measurements.push(measurement);

        while (!highest.empty() && highest.back() < measurement)
        {
            highest.pop_back();
        }

        highest.push_back(measurement);

        if (measurements.size() == interval)
        {
            cout << highest.front() << '\n';

            if (measurements.front() == highest.front())
            {
                highest.pop_front();
            }

            measurements.pop();
        }
    }

    return 0;
}
