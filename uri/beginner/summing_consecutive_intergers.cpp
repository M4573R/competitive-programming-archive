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

    int lower_limit;
    int length;

    cin >> lower_limit;

    while (cin >> length && length <= 0)
    { }

    cout << (2 * lower_limit + length - 1) * length / 2 << '\n';

    return 0;
}
