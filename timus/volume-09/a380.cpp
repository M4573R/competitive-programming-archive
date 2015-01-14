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

    unsigned  int row;
    char position;

    cin >> row >> position;

    if (row <= 2)
    {
        cout << (position == 'A' || position == 'D' ? "window" : "aisle");
    }
    else if (row <= 20)
    {
        cout << (position == 'A' || position == 'F' ? "window" : "aisle");
    }
    else
    {
        if (position == 'A' || position == 'K')
        {
            cout << "window";
        }
        else if (position == 'C' || position == 'D' ||
                 position == 'G' || position == 'H')
        {
            cout << "aisle";
        }
        else
        {
            cout << "neither";
        }
    }

    cout << '\n';

    return 0;
}
