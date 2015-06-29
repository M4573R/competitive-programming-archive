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

    unsigned int horizontal_sticks;
    unsigned int vertical_sticks;

    cin >> horizontal_sticks >> vertical_sticks;

    if (min(horizontal_sticks, vertical_sticks) % 2)
    {
        cout << "Akshat";
    }
    else
    {
        cout << "Malvika";
    }

    cout << '\n';

    return 0;
}
