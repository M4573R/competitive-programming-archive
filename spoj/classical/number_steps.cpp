#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int x;
        unsigned int y;

        cin >> x >> y;

        unsigned int number_at_point;

        if (x % 2 == 0)
        {
            number_at_point = 2 * x;
        }
        else
        {
            number_at_point = 2 * x - 1;
        }

        if (x == y)
        {
            cout << number_at_point << '\n';
        }
        else if (x == y + 2)
        {
            cout << number_at_point - 2 << '\n';
        }
        else
        {
            cout << "No Number\n";
        }
    }

    return 0;
}
