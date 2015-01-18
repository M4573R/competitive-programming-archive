#include <iostream>

using namespace std;

inline void use_io_optimizations()
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
        unsigned int columns;
        cin >> columns;

        int first_top, first_bottom;
        cin >> first_top >> first_bottom;

        bool can_be_closed {true};

        for (unsigned int i {1}; i < columns; ++i)
        {
            int top, bottom;
            cin >> top >> bottom;

            if (top - bottom != first_top - first_bottom)
            {
                can_be_closed = false;
            }
        }

        cout << (can_be_closed ? "yes" : "no") << '\n';

        if (test < test_cases - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
