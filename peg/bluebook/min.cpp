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

    cout << fixed << setprecision(2);

    unsigned int numbers;
    cin >> numbers;

    double minimum {1000};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        double number;
        cin >> number;

        minimum = min(minimum, number);
    }

    cout << minimum << '\n';

    return 0;
}
