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

    unsigned int number;
    unsigned int hours;
    double hourly_wage;

    cin >> number >> hours >> hourly_wage;

    cout << "NUMBER = "    << number              << '\n'
         << "SALARY = U$ " << hours * hourly_wage << '\n';

    return 0;
}
