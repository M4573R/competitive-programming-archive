#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr unsigned int priciest_menu {2048};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int price;
        cin >> price;

        unsigned int menus {0};

        for (unsigned int j {priciest_menu}; j >= 1; j /= 2)
        {
            menus += price / j;
            price %= j;
        }

        cout << menus << '\n';
    }

    return 0;
}
