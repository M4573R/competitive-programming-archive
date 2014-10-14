#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    long long number;
    vector<long long> numbers;

    while (cin >> number)
    {
        numbers.push_back(number);
    }

    cout << fixed << setprecision(4);

    for (vector<long long>::const_reverse_iterator i {numbers.crbegin()};
         i != numbers.crend();
         ++i)
    {
        cout << sqrtl(*i) << '\n';
    }

    return 0;
}
