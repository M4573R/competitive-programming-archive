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

    cout << fixed << setprecision(2);

    double money;
    double interest;
    unsigned int years;

    cin >> money >> interest >> years;

    for (unsigned int year {0}; year <= years; ++year)
    {
        cout << year << ' ' << money << '\n';
        money += money * interest / 100;
    }

    return 0;
}
