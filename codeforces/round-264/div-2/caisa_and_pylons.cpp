#include <algorithm>
#include <iostream>

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

    unsigned int pylons;
    cin >> pylons;

    unsigned int min_dollars {0};

    for (unsigned int i {0}; i < pylons; ++i)
    {
        unsigned int height;
        cin >> height;

        min_dollars = max(min_dollars, height);
    }

    cout << min_dollars << '\n';

    return 0;
}
