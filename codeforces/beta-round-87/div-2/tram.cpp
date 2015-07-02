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

    unsigned int stops;
    cin >> stops;

    unsigned int passengers   {0};
    unsigned int min_capacity {0};

    for (unsigned int i {0}; i < stops; ++i)
    {
        unsigned int exiting;
        unsigned int entering;

        cin >> exiting >> entering;

        passengers  += entering - exiting;
        min_capacity = max(min_capacity, passengers);
    }

    cout << min_capacity << '\n';

    return 0;
}
