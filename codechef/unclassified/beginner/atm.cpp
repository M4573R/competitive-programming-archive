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

    unsigned int cash;
    double balance;

    cin >> cash >> balance;

    if ((cash % 5 == 0) && (cash + 0.5 <= balance))
    {
        balance -= cash + 0.5;
    }

    cout << balance << '\n';

    return 0;
}
