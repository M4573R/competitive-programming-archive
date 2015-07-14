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

    int types;
    int money;

    cin >> types >> money;

    int max_sweets {-1};

    for (int i {0}; i < types; ++i)
    {
        int dollars;
        int cents;

        cin >> dollars >> cents;

        if (dollars * 100 + cents <= money * 100)
        {
            max_sweets = max(max_sweets, (100 - cents) % 100);
        }
    }

    cout << max_sweets << '\n';

    return 0;
}
