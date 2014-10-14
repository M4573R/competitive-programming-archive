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

    int a;
    int b;

    cin >> a >> b;

    cout << a + b;

    return 0;
}
