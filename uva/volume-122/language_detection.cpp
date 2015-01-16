#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, string> languages {
    {"HELLO",        "ENGLISH"},
    {"HOLA",         "SPANISH"},
    {"HALLO",        "GERMAN" },
    {"BONJOUR",      "FRENCH" },
    {"CIAO",         "ITALIAN"},
    {"ZDRAVSTVUJTE", "RUSSIAN"}
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string greeting;

    for (unsigned int test {1}; cin >> greeting && greeting != "#"; ++test)
    {
        cout << "Case " << test << ": ";

        if (languages.count(greeting))
        {
            cout << languages.at(greeting);
        }
        else
        {
            cout << "UNKNOWN";
        }

        cout << '\n';
    }

    return 0;
}
