#include <iomanip>
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

    for (unsigned int lines; cin >> lines && lines > 0; )
    {
        for (unsigned int i {1}; i <= lines; ++i)
        {
            for (unsigned int j {i}; j > 1; --j)
            {
                cout << setw(3) << j << ' ';
            }

            for (unsigned int j {1}; j <= lines + 1 - i; ++j)
            {
                cout << setw(3) << j << (j < lines + 1 - i ? ' ' : '\n');
            }
        }

        cout << '\n';
    }

    return 0;
}
