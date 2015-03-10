#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<string, string> responses {
    {"Paper",    "Scissors"},
    {"Rock",     "Paper"},
    {"Scissors", "Rock"},
    {"Fox",      "Foxen"}
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

    unsigned int rounds;
    cin >> rounds;

    for (string choice; cin >> choice && choice != "Foxen"; )
    {
        cout << responses.at(choice) << '\n';
    }

    return 0;
}
