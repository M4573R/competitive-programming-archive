#include <algorithm>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct OnBus
{
    unsigned int from_first;
    unsigned int other;

    OnBus():
        from_first(0),
        other(0)
    { }
};

int main()
{
    use_io_optimizations();

    unsigned int stations;
    cin >> stations;

    OnBus minimum;
    OnBus maximum;

    for (unsigned int i {0}; i < stations - 1; ++i)
    {
        unsigned int on;
        unsigned int off;

        cin >> on >> off;

        if (i == 0)
        {
            minimum.from_first += on;
            maximum.from_first += on;
        }
        else
        {
            minimum.other      -= off - min(minimum.from_first, off);
            minimum.from_first -= min(minimum.from_first, off);

            maximum.from_first -= off - min(maximum.other, off);
            maximum.other      -= min(maximum.other, off);

            minimum.other += on;
            maximum.other += on;
        }
    }

    cout << minimum.from_first << '\n'
         << maximum.from_first << '\n';

    return 0;
}
