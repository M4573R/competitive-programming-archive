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

    for (unsigned int i {1}; i <= 100; ++i)
    {
        if (i % 2 == 0)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
