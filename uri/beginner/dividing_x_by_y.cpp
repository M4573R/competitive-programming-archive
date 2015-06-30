#include <iomanip>
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

    cout << fixed << setprecision(1);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        int dividend;
        int divisor;

        cin >> dividend >> divisor;

        if (divisor == 0)
        {
            cout << "divisao impossivel";
        }
        else
        {
            cout << static_cast<double>(dividend) / divisor;
        }

        cout << '\n';
    }

    return 0;
}
