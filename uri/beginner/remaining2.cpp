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

    unsigned int modulo;
    cin >> modulo;

    if (modulo > 2)
    {
        for (unsigned int i {2}; i <= 10000; i += modulo)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
