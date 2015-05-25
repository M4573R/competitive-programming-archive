#include <iostream>
#include <set>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool has_distinct_digits(unsigned int number)
{
    set<unsigned int> digits;

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        unsigned int digit {i % 10};

        if (digits.count(digit))
        {
            return false;
        }

        digits.insert(digit);
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int year;
    cin >> year;

    while (!has_distinct_digits(++year))
    { }

    cout << year << '\n';

    return 0;
}
