#include <algorithm>
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

    cout << fixed << setprecision(4);

    unsigned int numbers;
    cin >> numbers;

    double maximum {-1e6};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        double number;
        cin >> number;

        maximum = max(maximum, number);
    }

    cout << maximum << '\n';

    return 0;
}
