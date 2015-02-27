#include <iostream>
#include <vector>

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

    unsigned int stormtroopers;
    cin >> stormtroopers;

    int gun_x;
    int gun_y;

    cin >> gun_x >> gun_y;

    vector<int> x(stormtroopers);
    vector<int> y(stormtroopers);

    for (unsigned int i {0}; i < stormtroopers; ++i)
    {
        cin >> x[i] >> y[i];

        x[i] -= gun_x;
        y[i] -= gun_y;
    }

    unsigned int shots {0};
    vector<bool> shot(stormtroopers);

    for (unsigned int i {0}; i < stormtroopers; ++i)
    {
        if (!shot[i])
        {
            ++shots;

            for (unsigned int j {0}; j < stormtroopers; ++j)
            {
                if (!shot[j] && x[i] * y[j] == x[j] * y[i])
                {
                    shot[j] = true;
                }
            }
        }
    }

    cout << shots << '\n';

    return 0;
}
