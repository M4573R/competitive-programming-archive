#include <algorithm>
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

    for (int length; cin >> length && length != 0; )
    {
        string highway;
        cin >> highway;

        int min_distance {length};
        int restaurant   {-1};
        int drugstore    {-1};

        for (int i {0}; i < length; ++i)
        {
            if (highway[i] == 'R')
            {
                restaurant = i;
            }
            else if (highway[i] == 'D')
            {
                drugstore = i;
            }
            else if (highway[i] == 'Z')
            {
                restaurant = i;
                drugstore  = i;
            }

            if (restaurant != -1 && drugstore != -1)
            {
                min_distance = min(min_distance, abs(restaurant - drugstore));
            }
        }

        cout << min_distance << '\n';
    }

    return 0;
}
