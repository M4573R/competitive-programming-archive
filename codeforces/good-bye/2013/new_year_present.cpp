#include <iostream>
#include <string>

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

    unsigned int wallets;
    cin >> wallets;

    string instructions;

    for (unsigned int i {0}; i < wallets; ++i)
    {
        unsigned int coins;
        cin >> coins;

        if (coins > 0)
        {
            instructions += 'P';
        }

        for (unsigned int j {1}; j < coins; ++j)
        {
            if (i < wallets - 1)
            {
                instructions += "RLP";
            }
            else
            {
                instructions += "LRP";
            }
        }

        if (i < wallets - 1)
        {
            instructions += 'R';
        }
    }

    cout << instructions << '\n';

    return 0;
}
