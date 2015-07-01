#include <iostream>
#include <map>
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

    map<string, map<string, bool>> beats {
        {"tesoura",
            {{"papel",   true},
             {"lagarto", true}}},

        {"papel",
            {{"pedra", true},
             {"Spock", true}}},

        {"pedra",
            {{"lagarto", true},
             {"tesoura", true}}},

        {"lagarto",
            {{"Spock", true},
             {"papel", true}}},

        {"Spock",
            {{"tesoura", true},
             {"pedra",   true}}},
    };

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        string sheldon;
        string raj;

        cin >> sheldon >> raj;

        cout << "Caso #" << test << ": ";

        cout << (beats[sheldon][raj] ? "Bazinga!" :
                 beats[raj][sheldon] ? "Raj trapaceou!" :
                                       "De novo!")
             << '\n';
    }

    return 0;
}
