#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<char, char> digits {
    {'A', '2'}, {'B', '2'}, {'C', '2'},
    {'D', '3'}, {'E', '3'}, {'F', '3'},
    {'G', '4'}, {'H', '4'}, {'I', '4'},
    {'J', '5'}, {'K', '5'}, {'L', '5'},
    {'M', '6'}, {'N', '6'}, {'O', '6'},
    {'P', '7'}, {'Q', '7'}, {'R', '7'}, {'S', '7'},
    {'T', '8'}, {'U', '8'}, {'V', '8'},
    {'W', '9'}, {'X', '9'}, {'Y', '9'}, {'Z', '9'},
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

    unsigned int test_cases;
    cin >> test_cases;
    cin.ignore();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string number;
        getline(cin, number);

        string converted;

        for (auto& symbol : number)
        {
            if (symbol != '-')
            {
                converted += (isalpha(symbol) ? digits.at(symbol) : symbol);
            }
        }

        cout << converted.substr(0, 3) << '-'
             << converted.substr(3, 3) << '-'
             << converted.substr(6, 4) << '\n';
    }

    return 0;
}
