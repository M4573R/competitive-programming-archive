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

    unsigned int lower;
    unsigned int upper;

    cin >> lower >> upper;

    unsigned int sum {0};

    for (unsigned int i {lower}; i <= upper; ++i)
    {
        sum += i * i;
    }

    cout << sum << '\n';

    return 0;
}
