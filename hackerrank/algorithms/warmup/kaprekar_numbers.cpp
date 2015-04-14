#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_kaprekar(unsigned int number)
{
    string squared {
        to_string(static_cast<unsigned long long>(number) * number)
    };

    auto middle = squared.length() / 2;
    auto prefix = stoull('0' + squared.substr(0, middle));
    auto suffix = stoull(squared.substr(middle));

    return prefix + suffix == number;
}

int main()
{
    use_io_optimizations();

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    string kaprekar_numbers;

    for (unsigned int i {lower_bound}; i <= upper_bound; ++i)
    {
        if (is_kaprekar(i))
        {
            kaprekar_numbers += ' ' + to_string(i);
        }
    }

    if (kaprekar_numbers.empty())
    {
        cout << "INVALID RANGE";
    }
    else
    {
        cout << kaprekar_numbers.substr(1);
    }

    cout << '\n';

    return 0;
}
