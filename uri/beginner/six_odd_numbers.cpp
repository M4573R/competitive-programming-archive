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

    unsigned int lower_limit;
    cin >> lower_limit;

    if (lower_limit % 2 == 0)
    {
        ++lower_limit;
    }

    for (unsigned int i {0}; i < 6; ++i)
    {
        cout << lower_limit + 2 * i << '\n';
    }

    return 0;
}
