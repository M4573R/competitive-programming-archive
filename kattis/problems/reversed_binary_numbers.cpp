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

    unsigned int reversed {0};

    for (unsigned int i {number}; i > 0; i /= 2)
    {
        reversed = reversed * 2 + i % 2;
    }

    cout << reversed << '\n';

    return 0;
}
