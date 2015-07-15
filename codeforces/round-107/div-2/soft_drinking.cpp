#include <algorithm>
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

    unsigned int friends;

    cin >> friends;

    unsigned int bottles;
    unsigned int bottle_size;
    unsigned int limes;
    unsigned int lime_slices;
    unsigned int salt;

    cin >> bottles >> bottle_size >> limes >> lime_slices >> salt;

    unsigned int needed_drink;
    unsigned int needed_salt;

    cin >> needed_drink >> needed_salt;

    cout << min({bottles * bottle_size / (friends * needed_drink),
                 limes   * lime_slices / friends,
                 salt                  / (friends * needed_salt)})
         << '\n';

    return 0;
}
