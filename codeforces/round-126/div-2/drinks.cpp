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

    cout << fixed << setprecision(12);

    unsigned int drinks;
    cin >> drinks;

    unsigned int sum {0};

    for (unsigned int i {0}; i < drinks; ++i)
    {
        unsigned int percentage;
        cin >> percentage;

        sum += percentage;
    }

    cout << static_cast<double>(sum) / drinks << '\n';

    return 0;
}
