#include <iostream>
#include <iomanip>

using namespace std;

constexpr double fee {0.50};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned short amount;
    double balance;

    cin >> amount >> balance;

    if ((amount % 5 == 0) && (amount + fee <= balance))
    {
        balance -= amount + fee;
    }

    cout << fixed << setprecision(2) << balance << '\n';

    return 0;
}
