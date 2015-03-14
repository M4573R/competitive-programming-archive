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
        unsigned int weight;
        cin >> weight;

        if (weight <= 30)
        {
            cout << 38;
        }
        else if (weight <= 50)
        {
            cout << 55;
        }
        else if (weight <= 100)
        {
            cout << 73;
        }
        else
        {
            cout << 73 + (weight - 100 + 49) / 50 * 24;
        }

        cout << '\n';
    }

    return 0;
}
