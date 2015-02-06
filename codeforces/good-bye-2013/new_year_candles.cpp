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

    unsigned int candles;
    unsigned int old_for_new;

    cin >> candles >> old_for_new;

    unsigned int hours {candles};

    for (unsigned int old_candles {candles}; old_candles >= old_for_new; )
    {
        unsigned int new_candles {old_candles / old_for_new};

        old_candles %= old_for_new;
        old_candles += new_candles;

        hours += new_candles;
    }

    cout << hours << '\n';

    return 0;
}
