/*
    ID:   gsshopo1
    PROG: dualpal
    LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

constexpr unsigned int lowest_base  {2};
constexpr unsigned int highest_base {10};

string number_in_base(unsigned int number, unsigned int base)
{
    string in_new_base;

    for (unsigned int i {number}; i > 0; i /= base)
    {
        in_new_base += i % base + '0';
    }

    if (number == 0)
    {
        in_new_base += number + '0';
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

bool is_dual_palindrome(unsigned int number)
{
    unsigned int palindromic_bases {0};

    for (unsigned int base {lowest_base}; base <= highest_base; ++base)
    {
        if (is_palindromic(number_in_base(number, base)))
        {
            ++palindromic_bases;
        }
    }

    return palindromic_bases >= 2;
}

int main()
{
    ifstream fin  {"dualpal.in"};
    ofstream fout {"dualpal.out"};

    unsigned int numbers_count;
    unsigned int lower_limit;

    fin >> numbers_count >> lower_limit;

    for (unsigned int i {lower_limit + 1}, found {0}; found < numbers_count; ++i)
    {
        if (is_dual_palindrome(i))
        {
            fout << i << '\n';
            ++found;
        }
    }

    return 0;
}
