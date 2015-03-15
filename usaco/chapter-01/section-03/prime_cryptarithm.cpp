/*
    ID:   gsshopo1
    PROG: crypt1
    LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;

bool is_good_number(unsigned int number, const vector<bool>& is_good_digit)
{
    for (unsigned int i {number}; i > 0; i /= 10)
    {
        if (!is_good_digit[i % 10])
        {
            return false;
        }
    }

    return true;
}

bool is_good_product(unsigned int x,
                     unsigned int y,
                     const vector<bool>& is_good_digit)
{
    unsigned int partial_a {x * (y % 10)};
    unsigned int partial_b {x * (y / 10 % 10)};
    unsigned int final     {x * y};

    if (partial_a / 100  == 0 || partial_a / 1000  != 0 ||
        partial_b / 100  == 0 || partial_b / 1000  != 0 ||
        final     / 1000 == 0 || final     / 10000 != 0)
    {
        return false;
    }

    return (is_good_number(x,         is_good_digit) &&
            is_good_number(y,         is_good_digit) &&
            is_good_number(partial_a, is_good_digit) &&
            is_good_number(partial_b, is_good_digit) &&
            is_good_number(final,     is_good_digit));
}

int main()
{
    ifstream fin  {"crypt1.in"};
    ofstream fout {"crypt1.out"};

    unsigned int digits;
    fin >> digits;

    vector<bool> is_good_digit(10);

    for (unsigned int i {0}; i < digits; ++i)
    {
        unsigned int digit;
        fin >> digit;

        is_good_digit[digit] = true;
    }

    unsigned int solutions {0};

    for (unsigned int i {100}; i < 1000; ++i)
    {
        for (unsigned int j {10}; j < 100; ++j)
        {
            if (is_good_product(i, j, is_good_digit))
            {
                ++solutions;
            }
        }
    }

    fout << solutions << '\n';

    return 0;
}
