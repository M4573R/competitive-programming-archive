/*
    ID:   gsshopo1
    PROG: palsquare
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

constexpr unsigned int lower_limit {1};
constexpr unsigned int upper_limit {300};

inline char digit_to_char(unsigned int digit)
{
    if (digit < 10)
    {
        return digit + '0';
    }

    return 'A' + (digit - 10);
}

string number_in_base(unsigned int number, unsigned int base)
{
    string in_new_base;

    for (unsigned int i {number}; i > 0; i /= base)
    {
        in_new_base += digit_to_char(i % base);
    }

    if (number == 0)
    {
        in_new_base += digit_to_char(number);
    }

    reverse(in_new_base.begin(), in_new_base.end());

    return in_new_base;
}

template <typename Sequence>
bool is_palindromic(const Sequence& sequence)
{
    return equal(sequence.cbegin(),
                 sequence.cbegin() + sequence.size() / 2,
                 sequence.crbegin());
}

int main()
{
    ifstream fin  {"palsquare.in"};
    ofstream fout {"palsquare.out"};

    unsigned int base;
    fin >> base;

    for (unsigned int i {lower_limit}; i <= upper_limit; ++i)
    {
        string number_in_new_base {number_in_base(i, base)};
        string square_in_new_base {number_in_base(i * i, base)};

        if (is_palindromic(square_in_new_base))
        {
            fout << number_in_new_base << ' ' << square_in_new_base << '\n';
        }
    }

    return 0;
}
