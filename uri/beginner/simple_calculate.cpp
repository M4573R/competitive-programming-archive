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

    unsigned int first_code;
    unsigned int first_units;
    double first_price;

    cin >> first_code >> first_units >> first_price;

    unsigned int second_code;
    unsigned int second_units;
    double second_price;

    cin >> second_code >> second_units >> second_price;

    cout << "VALOR A PAGAR: R$ "
         << first_units * first_price + second_units * second_price
         << '\n';

    return 0;
}
