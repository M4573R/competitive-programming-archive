#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string lock;
    cin >> lock;

    int difference {0};
    int last_hole  {0};

    for (string::size_type i {0}; i < lock.size(); ++i)
    {
        difference += (lock[i] == '(' ? 1 : -1);

        if (lock[i] == '#')
        {
            last_hole = i;
        }
    }

    int last_number {max(1, difference + 1)};
    difference = 0;

    for (string::size_type i {0}; i < lock.size(); ++i)
    {
        if (i == last_hole)
        {
            difference -= last_number;
        }
        else
        {
            difference += (lock[i] == '(' ? 1 : -1);
        }

        if (difference < 0)
        {
            cout << "-1\n";
            return 0;
        }
    }

    for (string::size_type i {0}; i < lock.size(); ++i)
    {
        if (lock[i] == '#')
        {
            cout << (i == last_hole ? last_number : 1) << '\n';
        }
    }

    return 0;
}
