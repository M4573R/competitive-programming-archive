#include <iomanip>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int increase_percentage(double salary)
{
    if (salary <= 400)
    {
        return 15;
    }
    else if (salary <= 800)
    {
        return 12;
    }
    else if (salary <= 1200)
    {
        return 10;
    }
    else if (salary <= 2000)
    {
        return 7;
    }
    else
    {
        return 4;
    }
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    double salary;
    cin >> salary;

    unsigned int percent {increase_percentage(salary)};
    double money_earned  {salary * percent / 100};

    cout << "Novo salario: "   << salary + money_earned << '\n'
         << "Reajuste ganho: " << money_earned          << '\n'
         << "Em percentual: "  << percent               << " %\n";

    return 0;
}
