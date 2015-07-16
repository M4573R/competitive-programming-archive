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

    unsigned int ranks;
    cin >> ranks;

    vector<unsigned int> years(ranks);

    for (unsigned int i {1}; i < ranks; ++i)
    {
        cin >> years[i];
    }

    unsigned int from;
    unsigned int to;

    cin >> from >> to;

    unsigned int needed_years {0};

    for (unsigned int i {from}; i < to; ++i)
    {
        needed_years += years[i];
    }

    cout << needed_years << '\n';

    return 0;
}
