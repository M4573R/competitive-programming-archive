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

    unsigned int total_coins {0};

    for (unsigned int i {0}; i < 5; ++i)
    {
        unsigned int coins;
        cin >> coins;

        total_coins += coins;
    }

    if (total_coins != 0 && total_coins % 5 == 0)
    {
        cout << total_coins / 5;
    }
    else
    {
        cout << -1;
    }

    cout << '\n';

    return 0;
}
