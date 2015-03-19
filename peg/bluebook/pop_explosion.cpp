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

    double rate;
    unsigned int current_population;
    unsigned int year;
    unsigned int target_population;

    cin >> rate
        >> current_population
        >> year
        >> target_population;

    for (double population = current_population; population < target_population; )
    {
        population += population * (rate / 100);
        ++year;
    }

    cout << year << '\n';

    return 0;
}
