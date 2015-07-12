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

    unsigned int people;
    cin >> people;

    unsigned int change_25 {0};
    unsigned int change_50 {0};

    unsigned int possible {true};

    for (unsigned int i {0}; i < people; ++i)
    {
        unsigned int money;
        cin >> money;

        if (money == 25)
        {
            ++change_25;
        }
        else if (money == 50)
        {
            if (change_25)
            {
                --change_25;
                ++change_50;
            }
            else
            {
                possible = false;
            }
        }
        else
        {
            if (change_25 && change_50)
            {
                --change_25;
                --change_50;
            }
            else if (change_25 >= 3)
            {
                change_25 -= 3;
            }
            else
            {
                possible = false;
            }
        }
    }

    cout << (possible ? "YES" : "NO") << '\n';

    return 0;
}
