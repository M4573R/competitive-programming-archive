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

    unsigned int steps;
    unsigned int multiples;

    cin >> steps >> multiples;

    if (multiples > steps)
    {
        cout << -1;
    }
    else
    {
        cout << ((steps + 1) / 2 + multiples - 1) / multiples * multiples;
    }

    cout << '\n';

    return 0;
}
