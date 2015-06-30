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

    for (unsigned int upper_limit; cin >> upper_limit && upper_limit > 0; )
    {
        for (unsigned int i {1}; i <= upper_limit; ++i)
        {
            cout << i << (i < upper_limit ? ' ' : '\n');
        }
    }

    return 0;
}
