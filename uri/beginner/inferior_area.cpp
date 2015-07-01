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

    cout << fixed << setprecision(1);

    char operation;
    cin >> operation;

    double sum {0};

    for (unsigned int i {0}; i < 12; ++i)
    {
        for (unsigned int j {0}; j < 12; ++j)
        {
            double element;
            cin >> element;

            if (i > j && i + j > 11)
            {
                sum += element;
            }
        }
    }

    cout << (operation == 'S' ? sum : sum / 66) << '\n';

    return 0;
}
