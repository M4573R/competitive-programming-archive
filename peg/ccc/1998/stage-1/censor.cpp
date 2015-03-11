#include <iostream>
#include <sstream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int lines;
    cin >> lines;
    cin.ignore();

    for (unsigned int i {0}; i < lines; ++i)
    {
        string line;
        getline(cin, line);

        istringstream input_line {line};

        for (string word; input_line >> word; )
        {
            cout << (word.length() == 4 ? "****" : word) << ' ';
        }

        cout << '\n';
    }

    return 0;
}
