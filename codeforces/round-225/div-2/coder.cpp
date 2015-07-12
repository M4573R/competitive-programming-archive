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

    unsigned int size;
    cin >> size;

    cout << (size * size + 1) / 2 << '\n';

    for (unsigned int i {0}; i < size; ++i)
    {
        for (unsigned int j {0}; j < size; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                cout << 'C';
            }
            else
            {
                cout << '.';
            }
        }

        cout << '\n';
    }

    return 0;
}
