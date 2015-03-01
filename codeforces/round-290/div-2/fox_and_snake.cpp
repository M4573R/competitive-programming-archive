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

    unsigned int rows;
    unsigned int columns;

    cin >> rows >> columns;

    string row_a (columns, '#');
    string row_b {string(columns - 1, '.') + '#'};
    string row_c {'#' + string(columns - 1, '.')};

    for (unsigned int i {0}; i < rows; ++i)
    {
        if (i % 2 == 0)
        {
            cout << row_a << '\n';
        }
        else if (i % 4 == 1)
        {
            cout << row_b << '\n';
        }
        else
        {
            cout << row_c << '\n';
        }
    }

    return 0;
}
