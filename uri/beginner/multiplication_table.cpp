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

    for (unsigned int i {1}; i <= 10; ++i)
    {
        cout << i << " x " << number << " = " << i * number << '\n';
    }

    return 0;
}
