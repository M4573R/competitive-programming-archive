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

    unsigned int left;
    unsigned int right;

    cin >> left >> right;

    unsigned int difference {left - right};

    if (difference % 10 == 9)
    {
        cout << difference - 1;
    }
    else
    {
        cout << difference + 1;
    }

    cout << '\n';

    return 0;
}
