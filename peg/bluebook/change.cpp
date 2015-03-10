#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<unsigned int> values {25, 10, 5, 1};
const vector<string>       names  {"quarter", "dime", "nickel", "cent"};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int money;
    cin >> money;

    cout << money << " cents requires ";

    for (unsigned int i {0}; i < values.size() && money > 0; ++i)
    {
        unsigned int coins {0};

        if (values[i] <= money)
        {
            coins += money / values[i];
            money %= values[i];
        }

        if (coins > 0)
        {
            cout << coins << ' ' << names[i];

            if (coins > 1)
            {
                cout << 's';
            }

            if (money > 0)
            {
                cout << ", ";
            }
        }
    }

    cout << ".\n";

    return 0;
}
