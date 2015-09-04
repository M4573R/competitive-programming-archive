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

    unsigned long long number;
    cin >> number;

    cout << number * number << '\n'
         << number          << '\n';

    return 0;
}
