#include <iostream>

using namespace std;

constexpr unsigned int mod {1000000007};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned long long a;
    unsigned long long b;

    cin >> a >> b;

    cout << (a * (a + 1) / 2 % mod * b % mod + a) * (b * (b - 1) / 2 % mod) % mod;

    return 0;
}
