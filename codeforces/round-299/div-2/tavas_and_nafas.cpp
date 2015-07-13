#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> up_to_19 {
    "zero",
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
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

vector<string> tenths {
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int score;
    cin >> score;

    if (score < 20)
    {
        cout << up_to_19[score];
    }
    else
    {
        cout << tenths[score / 10];

        if (score % 10)
        {
            cout << '-' << up_to_19[score % 10];
        }
    }

    cout << '\n';

    return 0;
}
