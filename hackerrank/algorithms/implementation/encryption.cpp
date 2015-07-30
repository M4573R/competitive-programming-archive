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

    string text;
    cin >> text;

    unsigned int rows;
    unsigned int columns;

    for (unsigned int i {9}; i >= 1; --i)
    {
        if (i * i >= text.size())
        {
            rows    = i;
            columns = i;
        }

        if ((i - 1) * i >= text.size())
        {
            rows    = i - 1;
            columns = i;
        }
    }

    for (unsigned int i {0}; i < columns; ++i)
    {
        for (unsigned int j {0}; j < rows; ++j)
        {
            if (i + j * columns < text.size())
            {
                cout << text[i + j * columns];
            }
        }

        cout << " \n"[i + 1 == columns];
    }

    return 0;
}
