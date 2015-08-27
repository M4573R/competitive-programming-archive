#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int max_time {60 * 60};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool all_green(const vector<unsigned int>& cycles, unsigned int time)
{
    for (auto cycle : cycles)
    {
        if (time % (2 * cycle) >= cycle - 5)
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

        vector<unsigned int> cycles;

        for (unsigned int cycle; in >> cycle; )
        {
            cycles.push_back(cycle);
        }

        unsigned int time {*min_element(cycles.cbegin(), cycles.cend()) * 2};

        while (time <= max_time && !all_green(cycles, time))
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
