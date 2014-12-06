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
        unsigned int divisions;
        cin >> divisions;

        unsigned int min_days = 0;

        while (divisions > 0)
        {
            ++min_days;
            divisions /= 2;
        }

        cout << min_days << '\n';
    }

    return 0;
}
