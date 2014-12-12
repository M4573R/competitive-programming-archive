/*
    ID:   gsshopo1
    PROG: test
    LANG: C++11
*/

#include <fstream>

using namespace std;

int main()
{
    ifstream fin  {"test.in"};
    ofstream fout {"test.out"};

    int first;
    int second;

    fin >> first >> second;

    fout << first + second << '\n';

    return 0;
}
