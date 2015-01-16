#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned long long max_dots;
    cin >> max_dots;

    cout << max_dots * (max_dots + 1) / 2 * (max_dots + 2) << '\n';

    return 0;
}
