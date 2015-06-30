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

    for (unsigned int i {0}; i <= 10; ++i)
    {
        for (unsigned int j {1}; j <= 3; ++j)
        {
            cout << "I=" << 0.2 * i << " J=" << 0.2 * i + j << '\n';
        }
    }

    return 0;
}
