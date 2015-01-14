#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int array_size;
    unsigned int number;

    cin >> array_size >> number;

    cout << array_size * (number + 1) << '\n';

    return 0;
}
