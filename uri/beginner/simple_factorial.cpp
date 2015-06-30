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

    unsigned int factorial {1};

    for (unsigned int i {1}; i <= number; ++i)
    {
        factorial *= i;
    }

    cout << factorial << '\n';

    return 0;
}
