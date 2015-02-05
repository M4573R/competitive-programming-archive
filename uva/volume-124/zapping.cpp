#include <algorithm>
#include <iostream>

using namespace std;

constexpr unsigned int channels {100};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (unsigned int from, to; cin >> from >> to && from != -1 && to != -1; )
    {
        if (from > to)
        {
            swap(from, to);
        }

        cout << min(to - from, channels - to + from) << '\n';
    }

    return 0;
}
