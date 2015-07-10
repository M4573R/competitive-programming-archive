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

    int balance;
    cin >> balance;

    cout << max({balance, balance / 10, balance / 100 * 10 + balance % 10}) << '\n';

    return 0;
}
