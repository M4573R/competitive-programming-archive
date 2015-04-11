#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(string& letters, string& digits, vector<bool>& mask)
{
    string input;
    cin >> input;

    for (auto symbol : input)
    {
        if (isalpha(symbol))
        {
            letters += symbol;
            mask.push_back(true);
        }
        else
        {
            digits += symbol;
            mask.push_back(false);
        }
    }
}

void write_output(const string& letters,
                  const string& digits,
                  const vector<bool>& mask)
{
    auto letter = letters.cbegin();
    auto digit  = digits.cbegin();

    for (auto is_letter : mask)
    {
        cout << (is_letter ? *(letter++) : *(digit++));
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string letters;
        string digits;
        vector<bool> mask;

        read_input(letters, digits, mask);

        sort(letters.begin(), letters.end());
        sort(digits.begin(),  digits.end());

        write_output(letters, digits, mask);
    }

    return 0;
}
