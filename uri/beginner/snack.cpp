#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const map<unsigned int, double> prices {
    {1, 4.0},
    {2, 4.5},
    {3, 5.0},
    {4, 2.0},
    {5, 1.5}
};

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    unsigned int code;
    unsigned int quantity;

    cin >> code >> quantity;

    cout << "Total: R$ " << quantity * prices.at(code) << '\n';

    return 0;
}
