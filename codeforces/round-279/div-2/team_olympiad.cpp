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

    unsigned int children;
    cin >> children;

    vector<unsigned int> programmers;
    vector<unsigned int> mathematicians;
    vector<unsigned int> athletes;

    for (unsigned int i {1}; i <= children; ++i)
    {
        unsigned int child;
        cin >> child;

        if (child == 1)
        {
            programmers.push_back(i);
        }
        else if (child == 2)
        {
            mathematicians.push_back(i);
        }
        else if (child == 3)
        {
            athletes.push_back(i);
        }
    }

    unsigned int teams {
        min({programmers.size(), mathematicians.size(), athletes.size()})
    };

    cout << teams << '\n';

    for (unsigned int i {0}; i < teams; ++i)
    {
        cout << programmers[i]    << ' '
             << mathematicians[i] << ' '
             << athletes[i]       << '\n';
    }

    return 0;
}
