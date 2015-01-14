#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int precision {4};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(precision);

    vector<long long> numbers;

    for (long long number; cin >> number; )
    {
        numbers.push_back(number);
    }

    for (auto number = numbers.crbegin(); number != numbers.crend(); ++number)
    {
        cout << sqrt(*number) << '\n';
    }

    return 0;
}
