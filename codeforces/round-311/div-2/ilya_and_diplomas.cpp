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

    unsigned int schoolchildren;
    cin >> schoolchildren;

    vector<unsigned int> lower(3);
    vector<unsigned int> upper(3);

    for (unsigned int i {0}; i < 3; ++i)
    {
        cin >> lower[i] >> upper[i];
    }

    unsigned int first  {min(upper[0], schoolchildren - lower[1] - lower[2])};
    unsigned int second {min(upper[1], schoolchildren - first - lower[2])};
    unsigned int third  {schoolchildren - first - second};

    cout << first << ' ' << second << ' ' << third << '\n';

    return 0;
}
