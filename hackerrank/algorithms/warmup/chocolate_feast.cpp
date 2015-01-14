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

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int money;
        unsigned int price;
        unsigned int wrappers_bonus;

        cin >> money >> price >> wrappers_bonus;

        unsigned int chocolates {money / price};
        unsigned int wrappers   {chocolates};

        while (wrappers >= wrappers_bonus)
        {
            unsigned int bonus_chocolates {wrappers / wrappers_bonus};

            chocolates += bonus_chocolates;
            wrappers    = wrappers % wrappers_bonus + bonus_chocolates;
        }

        cout << chocolates << '\n';
    }

    return 0;
}
