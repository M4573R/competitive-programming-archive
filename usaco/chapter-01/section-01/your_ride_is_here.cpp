/*
    ID:   gsshopo1
    PROG: ride
    LANG: C++11
*/

#include <fstream>
#include <string>

using namespace std;

constexpr unsigned int modulo {47};

inline unsigned int letter_to_number(char letter)
{
    return letter - 'A' + 1;
}

unsigned int name_to_number(const string& name)
{
    unsigned int number {1};

    for (auto letter : name)
    {
        number *= letter_to_number(letter);
    }

    return number;
}

int main()
{
    ifstream fin  {"ride.in"};
    ofstream fout {"ride.out"};

    string comet_name;
    string group_name;

    fin >> comet_name >> group_name;

    unsigned int comet_number {name_to_number(comet_name)};
    unsigned int group_number {name_to_number(group_name)};

    if (comet_number % modulo == group_number % modulo)
    {
        fout << "GO";
    }
    else
    {
        fout << "STAY";
    }

    fout << '\n';

    return 0;
}
