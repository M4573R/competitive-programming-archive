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
        double first;
        double second;
        double third;

        cin >> first >> second >> third;

        cout << (2 * first + 3 * second + 5 * third) / 10 << '\n';
    }

    return 0;
}
