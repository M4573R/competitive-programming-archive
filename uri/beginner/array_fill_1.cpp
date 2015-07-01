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

    for (unsigned int i {0}; i < 10; ++i)
    {
        cout << "N[" << i << "] = " << number << '\n';
        number *= 2;
    }

    return 0;
}
