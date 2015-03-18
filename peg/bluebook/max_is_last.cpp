#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

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

    unsigned int numbers_count;
    cin >> numbers_count;

    vector<double> numbers(numbers_count);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    double maximum {*max_element(numbers.cbegin(), numbers.cend())};

    for (auto number : numbers)
    {
        if (number != maximum)
        {
            cout << number << '\n';
        }
    }

    cout << maximum << '\n';

    return 0;
}
