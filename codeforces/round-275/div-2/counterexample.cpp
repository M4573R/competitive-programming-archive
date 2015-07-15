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

    unsigned long long lower;
    unsigned long long upper;

    cin >> lower >> upper;

    if (lower % 2)
    {
        ++lower;
    }

    if (lower + 2 > upper)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << lower << ' ' << lower + 1 << ' ' << lower + 2 << '\n';
    }

    return 0;
}
