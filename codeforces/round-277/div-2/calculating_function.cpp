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

    long long number;
    cin >> number;

    if (number % 2 == 0)
    {
        cout << number / 2;
    }
    else
    {
        cout << number / 2 - number;
    }

    cout << '\n';

    return 0;
}
