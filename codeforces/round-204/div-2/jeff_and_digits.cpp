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

    unsigned int cards;
    cin >> cards;

    unsigned int zeros {0};
    unsigned int fives {0};

    for (unsigned int i {0}; i < cards; ++i)
    {
        unsigned int card;
        cin >> card;

        if (card == 0)
        {
            ++zeros;
        }
        else
        {
            ++fives;
        }
    }

    if (zeros == 0)
    {
        cout << -1 << '\n';
    }
    else if (fives < 9)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << string(fives - fives % 9, '5') + string(zeros, '0') << '\n';
    }

    return 0;
}
