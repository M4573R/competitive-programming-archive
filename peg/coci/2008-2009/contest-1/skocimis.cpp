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

    unsigned int a;
    unsigned int b;
    unsigned int c;

    cin >> a >> b >> c;

    cout << max(b - a, c - b) - 1 << '\n';

    return 0;
}
