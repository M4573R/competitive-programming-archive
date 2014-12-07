/*
    ID:   gsshopo1
    PROG: namenum
    LANG: C++11
*/

#include <fstream>
#include <map>
#include <string>

using namespace std;

const map<char, char> letters_to_digits {
    {'A', '2'}, {'B', '2'}, {'C', '2'},
    {'D', '3'}, {'E', '3'}, {'F', '3'},
    {'G', '4'}, {'H', '4'}, {'I', '4'},
    {'J', '5'}, {'K', '5'}, {'L', '5'},
    {'M', '6'}, {'N', '6'}, {'O', '6'},
    {'P', '7'}, {'R', '7'}, {'S', '7'},
    {'T', '8'}, {'U', '8'}, {'V', '8'},
    {'W', '9'}, {'X', '9'}, {'Y', '9'}
};

int main()
{
    ifstream fin  {"namenum.in"};
    ofstream fout {"namenum.out"};

    string serial_number;
    fin >> serial_number;

    ifstream dictionary {"dict.txt"};

    unsigned int matches {0};

    for (string entry; dictionary >> entry; )
    {
        if (serial_number.size() != entry.size())
        {
            continue;
        }

        bool are_matching {true};

        for (string::size_type i {0}; i < entry.size() && are_matching; ++i)
        {
            if (letters_to_digits.count(entry[i]) == 0 ||
                serial_number[i] != letters_to_digits.at(entry[i]))
            {
                are_matching = false;
            }
        }

        if (are_matching)
        {
            fout << entry << '\n';
            ++matches;
        }
    }

    if (matches == 0)
    {
        fout << "NONE\n";
    }

    return 0;
}
