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

    int a_sides;
    int b_sides;

    cin >> a_sides >> b_sides;

    int ways {max(0, min(9, a_sides) - max(1, 10 - b_sides) + 1)};

    if (ways == 1)
    {
        cout << "There is 1 way to get the sum 10.";
    }
    else
    {
        cout << "There are " << ways << " ways to get the sum 10.";
    }

    cout << '\n';

    return 0;
}
