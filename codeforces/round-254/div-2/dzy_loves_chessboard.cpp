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

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    for (unsigned int i {0}; i < rows; ++i)
    {
        for (unsigned int j {0}; j < columns; ++j)
        {
            char cell;
            cin >> cell;

            if (cell == '.')
            {
                if ((i + j) % 2 == 0)
                {
                    cell = 'W';
                }
                else
                {
                    cell = 'B';
                }
            }

            cout << cell;
        }

        cout << '\n';
    }

    return 0;
}
