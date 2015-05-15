#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int upper_limit(unsigned int digits)
{
    unsigned int max {0};

    for (unsigned int i {0}; i < digits; ++i)
    {
        max = 10 * max + 9;
    }

    return max;
}

unsigned int digits_sum(unsigned int number)
{
    unsigned int sum {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        sum += i % 10;
    }

    return sum;
}

vector<unsigned int> sums_frequencies(unsigned int digits)
{
    vector<unsigned int> frequencies(9 * digits + 1);

    for (unsigned int i {0}; i <= upper_limit(digits); ++i)
    {
        ++frequencies[digits_sum(i)];
    }

    return frequencies;
}

int main()
{
    use_io_optimizations();

    unsigned int digits;
    cin >> digits;

    vector<unsigned int> frequencies {sums_frequencies(digits / 2)};

    unsigned int lucky_tickets {0};

    for (auto frequency : frequencies)
    {
        lucky_tickets += frequency * frequency;
    }

    cout << lucky_tickets << '\n';

    return 0;
}
