#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr unsigned int dwarfs {7};

const vector<int> coefficients {
    1, 3, 2, 6, 4, 5
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string number;
    cin >> number;

    unsigned int equivalent_number {0};
    unsigned int coeffitient_index {0};

    for (auto digit = number.crbegin(); digit != number.crend(); ++digit)
    {
        equivalent_number += coefficients[coeffitient_index] * (*digit - '0');
        coeffitient_index  = (coeffitient_index + 1) % coefficients.size();
    }

    cout << equivalent_number % dwarfs << '\n';

    return 0;
}
