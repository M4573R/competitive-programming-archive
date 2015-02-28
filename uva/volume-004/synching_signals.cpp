#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const unsigned int max_time {60 * 60};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool all_green(unsigned int time, const vector<unsigned int>& cycles)
{
    for (unsigned int i {0}; i < cycles.size(); ++i)
    {
        if (time % (2 * cycles[i]) >= cycles[i] - 5)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int set {1};

    for (string line; getline(cin, line) && !line.empty(); ++set)
    {
        istringstream in {line};

        unsigned int min_cycle {max_time};
        vector<unsigned int> cycles;

        for (unsigned int cycle; in >> cycle; )
        {
            cycles.push_back(cycle);
            min_cycle = min(min_cycle, cycle);
        }

        unsigned int time {2 * min_cycle};

        while (time <= max_time && !all_green(time, cycles))
        {
            ++time;
        }

        if (time > max_time)
        {
            cout << "Set " << set << " is unable to synch after one hour.\n";
        }
        else
        {
            cout << "Set " << set << " synchs again at "
                 << time / 60 << " minute(s) and "
                 << time % 60 << " second(s) after all turning green.\n";
        }
    }

    return 0;
}
