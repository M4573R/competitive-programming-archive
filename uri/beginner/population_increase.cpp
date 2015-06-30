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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int population_a;
        unsigned int population_b;

        double growth_a;
        double growth_b;

        cin >> population_a >> population_b >> growth_a >> growth_b;

        unsigned int years {0};

        while (years <= 100 && population_a <= population_b)
        {
            population_a += population_a * growth_a / 100;
            population_b += population_b * growth_b / 100;

            ++years;
        }

        if (years <= 100)
        {
            cout << years << " anos.";
        }
        else
        {
            cout << "Mais de 1 seculo.";
        }

        cout << '\n';
    }

    return 0;
}
