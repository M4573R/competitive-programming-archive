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

    int n;
    cin >> n;

    if (n > 0)
    {
        cout << n * (n + 1) / 2;
    }
    else
    {
        cout << n * (-n + 1) / 2 + 1;
    }

    return 0;
}
