#include <iostream>
#include <map>

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

    map<unsigned int, int> slides {
        {9,   25},
        {40,  24},
        {67,  19},
        {54, -35},
        {90, -42},
        {99, -22}
    };

    for (unsigned int position {1}, dice; cin >> dice; )
    {
        if (dice == 0)
        {
            cout << "You Quit!\n";
            break;
        }

        if (position + dice <= 100)
        {
            position += dice;
            position += slides[position];
        }

        cout << "You are now on square " << position << '\n';

        if (position == 100)
        {
            cout << "You Win!\n";
            break;
        }
    }

    return 0;
}
