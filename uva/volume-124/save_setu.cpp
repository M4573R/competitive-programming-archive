#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int money {0};

    unsigned int operations;
    cin >> operations;

    for (unsigned int i {0}; i < operations; ++i)
    {
        string type;
        cin >> type;

        if (type == "donate")
        {
            unsigned int amount;
            cin >> amount;

            money += amount;
        }
        else
        {
            cout << money << '\n';
        }
    }

    return 0;
}
