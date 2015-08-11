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

    unsigned int base;
    unsigned int number;

    cin >> base >> number;

    unsigned int divisions {0};

    while (number % base == 0)
    {
        number /= base;
        ++divisions;
    }

    if (number == 1)
    {
        cout << "YES\n"
             << divisions - 1 << '\n';
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
