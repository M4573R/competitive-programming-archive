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

    unsigned int lines;
    cin >> lines;

    for (unsigned int i {0}; i < lines; ++i)
    {
        for (unsigned int j {0}; j < 3; ++j)
        {
            cout << j + 4 * i + 1 << ' ';
        }

        cout << "PUM\n";
    }

    return 0;
}
