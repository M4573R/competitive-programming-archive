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

    unsigned int length;
    unsigned int coefficient;

    cin >> length >> coefficient;

    for (unsigned int i {length}; i > length - coefficient; --i)
    {
        cout << i << ' ';
    }

    for (unsigned int i {1}; i <= length - coefficient; ++i)
    {
        cout << i << " \n"[i == length - coefficient];
    }

    return 0;
}
