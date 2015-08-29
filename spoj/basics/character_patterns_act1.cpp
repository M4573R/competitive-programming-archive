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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int rows;
        unsigned int columns;

        cin >> rows >> columns;

        for (unsigned int i {0}; i < rows; ++i)
        {
            for (unsigned int j {0}; j < columns; ++j)
            {
                cout << ((i + j) % 2 == 0 ? '*' : '.');
            }

            cout << '\n';
        }

        if (test + 1 < test_cases)
        {
            cout << '\n';
        }
    }

    return 0;
}
