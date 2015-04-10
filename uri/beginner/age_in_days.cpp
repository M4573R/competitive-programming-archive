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

    unsigned int time;
    cin >> time;

    unsigned int years  {time / 365};
    unsigned int months {time % 365 / 30};
    unsigned int days   {time % 365 % 30};

    cout << years  << " ano(s)"  << '\n'
         << months << " mes(es)" << '\n'
         << days   << " dia(s)"  << '\n';

    return 0;
}
