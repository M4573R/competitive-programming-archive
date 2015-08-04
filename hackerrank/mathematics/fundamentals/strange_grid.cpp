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

    unsigned long long row;
    unsigned long long column;

    cin >> row >> column;

    cout << (row - 1) / 2 * 10 + (row % 2 == 0) + (column - 1) * 2 << '\n';

    return 0;
}
