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
    unsigned int islands;

    cin >> size >> islands;

    if (islands > (size * size + 1) / 2)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        for (unsigned int i {0}; i < size; ++i)
        {
            for (unsigned int j {0}; j < size; ++j)
            {
                if (islands > 0 && (i + j) % 2 == 0)
                {
                    cout << 'L';
                    --islands;
                }
                else
                {
                    cout << 'S';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
