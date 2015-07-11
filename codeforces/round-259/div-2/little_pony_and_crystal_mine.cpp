#include <cstdlib>
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

    int size;
    cin >> size;

    for (int i {0}; i < size; ++i)
    {
        for (int j {0}; j < size; ++j)
        {
            if (abs(i - size / 2) + abs(j - size / 2) <= size / 2)
            {
                cout << 'D';
            }
            else
            {
                cout << '*';
            }
        }

        cout << '\n';
    }

    return 0;
}
