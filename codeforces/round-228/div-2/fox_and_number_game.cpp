#include <algorithm>
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

    unsigned int numbers;
    cin >> numbers;

    unsigned int gcd {0};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        gcd = __gcd(gcd, number);
    }

    cout << gcd * numbers << '\n';

    return 0;
}
