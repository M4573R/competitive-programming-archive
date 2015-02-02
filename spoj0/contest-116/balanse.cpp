#include <iostream>

using namespace std;

inline void use_oi_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_oi_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned long long coins;
        unsigned int counterfeit;

        cin >> coins >> counterfeit;

        if (coins == 1)
        {
            cout << "1\n";
            continue;
        }

        unsigned long long min_measurements = 0;

        while (coins >= 2)
        {
            ++min_measurements;
            coins = (coins + 2) / 3;
        }

        cout << min_measurements << '\n';
    }

    return 0;
}
