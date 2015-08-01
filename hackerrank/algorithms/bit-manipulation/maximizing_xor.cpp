#include <algorithm>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    unsigned int max_xor {0};

    for (unsigned int i {lower_bound}; i < upper_bound; ++i)
    {
        for (unsigned int j {i + 1}; j <= upper_bound; ++j)
        {
            max_xor = max(max_xor, i ^ j);
        }
    }

    cout << max_xor << '\n';

    return 0;
}
