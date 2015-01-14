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

    int initial_offer;
    int initial_fair;
    int increase;
    int decrease;

    cin >> initial_offer >> increase >> initial_fair >> decrease;

    if (initial_fair < initial_offer)
    {
        cout << initial_offer << '\n';
        return 0;
    }

    for (int lower_bound {initial_offer}, upper_bound {initial_fair}; ; )
    {
        lower_bound += increase;

        if (lower_bound > upper_bound)
        {
            cout << upper_bound;
            break;
        }

        upper_bound -= decrease;

        if (upper_bound < lower_bound)
        {
            cout << lower_bound;
            break;
        }
    }

    cout << '\n';

    return 0;
}
