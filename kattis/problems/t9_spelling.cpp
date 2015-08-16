#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<char, char> buttons {
    {' ', '0'},
    {'a', '2'}, {'b', '2'}, {'c', '2'},
    {'d', '3'}, {'e', '3'}, {'f', '3'},
    {'g', '4'}, {'h', '4'}, {'i', '4'},
    {'j', '5'}, {'k', '5'}, {'l', '5'},
    {'m', '6'}, {'n', '6'}, {'o', '6'},
    {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
    {'t', '8'}, {'u', '8'}, {'v', '8'},
    {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}
};

const map<char, unsigned int> presses {
    {' ', 1},
    {'a', 1}, {'b', 2}, {'c', 3},
    {'d', 1}, {'e', 2}, {'f', 3},
    {'g', 1}, {'h', 2}, {'i', 3},
    {'j', 1}, {'k', 2}, {'l', 3},
    {'m', 1}, {'n', 2}, {'o', 3},
    {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4},
    {'t', 1}, {'u', 2}, {'v', 3},
    {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4}
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

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        cout << "Case #" << test << ": ";

        string message;
        getline(cin, message);

        for (auto i = message.cbegin(); i != message.cend(); ++i)
        {
            if (i != message.cbegin() && buttons.at(*i) == buttons.at(*(i - 1)))
            {
                cout << ' ';
            }

            cout << string(presses.at(*i), buttons.at(*i));
        }

        cout << '\n';
    }

    return 0;
}
