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

    unsigned int brothers;
    cin >> brothers;

    for (unsigned int i {0}; i < brothers; ++i)
    {
        for (unsigned int j {0}; j < brothers; ++j)
        {
            cout << j * brothers + 1 + (i + j) % brothers
                 << (j + 1 < brothers ? ' ' : '\n');
        }
    }

    return 0;
}
