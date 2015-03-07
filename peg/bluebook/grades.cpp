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
        int number;
        cin >> number;

        if (number < 0)
        {
            cout << 'X';
        }
        else if (number < 50)
        {
            cout << 'F';
        }
        else if (number < 60)
        {
            cout << 'D';
        }
        else if (number < 70)
        {
            cout << 'C';
        }
        else if (number < 80)
        {
            cout << 'B';
        }
        else if (number < 101)
        {
            cout << 'A';
        }
        else
        {
            cout << 'X';
        }

        cout << '\n';
    }

    return 0;
}
