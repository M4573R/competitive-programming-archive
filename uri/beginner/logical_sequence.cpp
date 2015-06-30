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

    for (unsigned int i {1}; i <= number; ++i)
    {
        cout << i << ' ' << i * i     << ' ' << i * i * i     << '\n'
             << i << ' ' << i * i + 1 << ' ' << i * i * i + 1 << '\n';
    }

    return 0;
}
