#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char boy  {'B'};
constexpr char girl {'G'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int children;
    unsigned int seconds;

    cin >> children >> seconds;

    string arrangement;
    cin >> arrangement;

    for (unsigned int i {0}; i < seconds; ++i)
    {
        for (auto j = arrangement.begin(); j < arrangement.end() - 1; ++j)
        {
            if (*j == boy && *(j + 1) == girl)
            {
                swap(*j, *(j + 1));
                ++j;
            }
        }
    }

    cout << arrangement;

    return 0;
}
