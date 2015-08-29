#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> pixel {
    "***",
    "*..",
    "*.."
};

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
            for (const auto& element : pixel)
            {
                for (unsigned int j {0}; j < columns; ++j)
                {
                    cout << element;
                }

                cout << "*\n";
            }
        }

        cout << string(3 * columns + 1, '*') << '\n';

        if (test + 1 < test_cases)
        {
            cout << '\n';
        }
    }

    return 0;
}
