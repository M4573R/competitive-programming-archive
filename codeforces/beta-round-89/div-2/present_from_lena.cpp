#include <cstdlib>
#include <iostream>
#include <string>

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

    int size;
    cin >> size;

    for (int i {0}; i < 2 * size + 1; ++i)
    {
        cout << string(2 * abs(size - i), ' ');

        for (int j {0}; j < size - abs(size - i); ++j)
        {
            cout << j << ' ';
        }

        cout << size - abs(size - i);

        for (int j {size - abs(size - i) - 1}; j >= 0; --j)
        {
            cout << ' ' << j;
        }

        cout << '\n';
    }

    return 0;
}
