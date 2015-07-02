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

    unsigned int steps;
    unsigned int multiples;

    cin >> steps >> multiples;

    if (multiples > steps)
    {
        cout << -1 << '\n';
    }
    else
    {
        unsigned int min_steps {(steps + 1) / 2};

        if (min_steps % multiples != 0)
        {
            min_steps += multiples - min_steps % multiples;
        }

        cout << min_steps << '\n';
    }

    return 0;
}
