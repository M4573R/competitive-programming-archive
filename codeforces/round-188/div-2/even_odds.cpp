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

    unsigned long long numbers;
    unsigned long long position;

    cin >> numbers >> position;

    unsigned long long odd  {(numbers + 1) / 2};
    unsigned long long even {numbers - odd};

    if (position <= odd)
    {
        cout << 2 * position - 1;
    }
    else
    {
        cout << 2 * (position - odd);
    }

    cout << '\n';

    return 0;
}
