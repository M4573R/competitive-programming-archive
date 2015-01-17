#include <cstdio>
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

    int volume;
    int cover;
    int from;
    int to;

    cin >> volume >> cover >> from >> to;

    cout << abs((to - from) * (volume + 2 * cover) - volume) << '\n';

    return 0;
}
