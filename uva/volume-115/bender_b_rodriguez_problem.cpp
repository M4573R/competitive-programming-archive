#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, map<string, string>> outcomes {
    {"+x", {{"+y", "+y"},
            {"-y", "-y"},
            {"+z", "+z"},
            {"-z", "-z"}}},

    {"-x", {{"+y", "-y"},
            {"-y", "+y"},
            {"+z", "-z"},
            {"-z", "+z"}}},

    {"+y", {{"+y", "-x"},
            {"-y", "+x"},
            {"+z", "+y"},
            {"-z", "+y"}}},

    {"-y", {{"+y", "+x"},
            {"-y", "-x"},
            {"+z", "-y"},
            {"-z", "-y"}}},

    {"+z", {{"+y", "+z"},
            {"-y", "+z"},
            {"+z", "-x"},
            {"-z", "+x"}}},

    {"-z", {{"+y", "-z"},
            {"-y", "-z"},
            {"+z", "+x"},
            {"-z", "-x"}}}
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

    for (unsigned int length; cin >> length && length != 0; )
    {
        string direction {"+x"};

        for (unsigned int i {0}; i < length - 1; ++i)
        {
            string decision;
            cin >> decision;

            if (decision != "No")
            {
                direction = outcomes.at(direction).at(decision);
            }
        }

        cout << direction << '\n';
    }

    return 0;
}
