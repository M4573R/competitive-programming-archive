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

    unsigned int n;
    cin >> n;

    cout << (((n + 1) / 2) % 2 == 0 ? "black" : "grimy") << '\n';

    return 0;
}
