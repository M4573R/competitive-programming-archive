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

    unsigned int days;
    unsigned int bowls;
    unsigned int plates;

    cin >> days >> bowls >> plates;

    unsigned int washes {0};

    for (unsigned int i {0}; i < days; ++i)
    {
        unsigned int dish;
        cin >> dish;

        if (dish == 1)
        {
            if (bowls > 0)
            {
                --bowls;
            }
            else
            {
                ++washes;
            }
        }
        else
        {
            if (plates > 0)
            {
                --plates;
            }
            else if (bowls > 0)
            {
                --bowls;
            }
            else
            {
                ++washes;
            }
        }
    }

    cout << washes << '\n';

    return 0;
}
