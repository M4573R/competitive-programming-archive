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

    unsigned int problems;
    cin >> problems;

    for (unsigned int i {0}; i < problems; ++i)
    {
        int a, b;
        cin >> a >> b;

        cout << a + b << '\n';
    }

    return 0;
}
