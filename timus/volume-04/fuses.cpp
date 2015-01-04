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

    unsigned int from;
    unsigned int to;

    cin >> from >> to;

    cout << (to - from + from % 2 + to % 2) / 2 << '\n';

    return 0;
}
