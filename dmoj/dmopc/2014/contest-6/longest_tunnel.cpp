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

    unsigned int tunnels;
    cin >> tunnels;

    unsigned max_length {0};

    for (unsigned int i {0}; i < tunnels; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        max_length = max(max_length, to - from);
    }

    cout << max_length << '\n';

    return 0;
}
