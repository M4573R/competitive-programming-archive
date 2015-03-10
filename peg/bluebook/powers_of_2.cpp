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

    unsigned int number;
    cin >> number;

    unsigned int power {0};

    while ((1 << power) < number)
    {
        ++power;
    }

    cout << power << '\n';

    return 0;
}
