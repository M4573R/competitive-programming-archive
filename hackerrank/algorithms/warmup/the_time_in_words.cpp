#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> to_words {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "quarter",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "twenty one",
    "twenty two",
    "twenty three",
    "twenty four",
    "twenty five",
    "twenty six",
    "twenty seven",
    "twenty eight",
    "twenty nine",
    "half"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
string units(unsigned int minutes)
{
    if (minutes % 15 == 0)
    {
        return " ";
    }
    else if (minutes == 1)
    {
        return " minute ";
    }
    else
    {
        return " minutes ";
    }
}

int main()
{
    use_io_optimizations();

    unsigned int hours;
    unsigned int minutes;

    cin >> hours >> minutes;

    if (minutes == 0)
    {
        cout << to_words[hours] << " o' clock";
    }
    else if (minutes <= 30)
    {
        cout << to_words[minutes]
             << units(minutes)
             << "past "
             << to_words[hours];
    }
    else
    {
        cout << to_words[60 - minutes]
             << units(60 - minutes)
             << "to "
             << to_words[(hours + 1) % 12];
    }

    cout << '\n';

    return 0;
}
