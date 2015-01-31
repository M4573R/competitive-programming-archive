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

    unsigned int digits;
    unsigned int base;

    cin >> digits >> base;

    unsigned int zero_ending     {0};
    unsigned int non_zero_ending {base - 1};

    for (unsigned int i {1}; i < digits; ++i)
    {
        swap(zero_ending, non_zero_ending);
        non_zero_ending = (base - 1) * (zero_ending + non_zero_ending);
    }

    cout << zero_ending + non_zero_ending << '\n';

    return 0;
}
