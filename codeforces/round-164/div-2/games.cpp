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

    unsigned int teams;
    cin >> teams;

    vector<unsigned int> home_colors(teams);
    vector<unsigned int> guest_colors(teams);

    for (unsigned int i {0}; i < teams; ++i)
    {
        cin >> home_colors[i] >> guest_colors[i];
    }

    unsigned int switches {0};

    for (unsigned int i {0}; i < teams; ++i)
    {
        for (unsigned int j {0}; j < teams; ++j)
        {
            if (home_colors[i] == guest_colors[j])
            {
                ++switches;
            }
        }
    }

    cout << switches << '\n';

    return 0;
}
