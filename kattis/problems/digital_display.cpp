#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const map<char, vector<string>> display {
    {'0', {"+---+",
           "|   |",
           "|   |",
           "+   +",
           "|   |",
           "|   |",
           "+---+"}},

    {'1', {"    +",
           "    |",
           "    |",
           "    +",
           "    |",
           "    |",
           "    +"}},

    {'2', {"+---+",
           "    |",
           "    |",
           "+---+",
           "|    ",
           "|    ",
           "+---+"}},

    {'3', {"+---+",
           "    |",
           "    |",
           "+---+",
           "    |",
           "    |",
           "+---+"}},

    {'4', {"+   +",
           "|   |",
           "|   |",
           "+---+",
           "    |",
           "    |",
           "    +"}},

    {'5', {"+---+",
           "|    ",
           "|    ",
           "+---+",
           "    |",
           "    |",
           "+---+"}},

    {'6', {"+---+",
           "|    ",
           "|    ",
           "+---+",
           "|   |",
           "|   |",
           "+---+"}},

    {'7', {"+---+",
           "    |",
           "    |",
           "    +",
           "    |",
           "    |",
           "    +"}},

    {'8', {"+---+",
           "|   |",
           "|   |",
           "+---+",
           "|   |",
           "|   |",
           "+---+"}},

    {'9', {"+---+",
           "|   |",
           "|   |",
           "+---+",
           "    |",
           "    |",
           "+---+"}},

    {':', {" ",
           " ",
           "o",
           " ",
           "o",
           " ",
           " "}},

    {' ', {"  ",
           "  ",
           "  ",
           "  ",
           "  ",
           "  ",
           "  "}}
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

    for (string time; cin >> time && time != "end"; )
    {
        for (unsigned int i {0}; i < 7; ++i)
        {
            for (auto j = time.cbegin(); j != time.cend(); ++j)
            {
                if (j != time.cbegin())
                {
                    cout << display.at(' ')[i];
                }

                cout << display.at(*j)[i];
            }

            cout << '\n';
        }

        cout << "\n\n";
    }

    cout << "end\n";

    return 0;
}
