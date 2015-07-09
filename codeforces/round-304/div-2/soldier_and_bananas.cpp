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

    unsigned long long price;
    unsigned long long money;
    unsigned long long bananas;

    cin >> price >> money >> bananas;

    unsigned long long total_cost {bananas * (bananas + 1) / 2 * price};

    cout << (total_cost > money ? total_cost - money : 0) << '\n';

    return 0;
}
