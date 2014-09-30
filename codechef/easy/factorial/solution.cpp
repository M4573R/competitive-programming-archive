#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

unsigned int factorial_trailing_zeros(unsigned int n)
{
    unsigned int trailing_zeros {0};

    for (unsigned int i {5}; i <= n; i *= 5)
    {
        trailing_zeros += n / i;
    }

    return trailing_zeros;
}

int main()
{
    use_io_optimizations();

    unsigned int input_size;
    cin >> input_size;

    for (unsigned int i {0}; i < input_size; ++i)
    {
        unsigned int n;
        cin >> n;

        cout << factorial_trailing_zeros(n) << '\n';
    }

    return 0;
}
