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

    for (unsigned int i {1}; i <= 9; i += 2)
    {
        for (unsigned int j {6 + i}; j >= 4 + i; --j)
        {
            cout << "I=" << i << " J=" << j << '\n';
        }
    }

    return 0;
}
