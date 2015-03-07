#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, string> translations {
    {"CU",    "see you"},
    {":-)",   "I'm happy"},
    {":-(",   "I'm unhappy"},
    {";-)",   "wink"},
    {":-P",   "stick out my tongue"},
    {"(~.~)", "seepy"},
    {"TA",    "totally awesome"},
    {"CCC",   "Canadian Computing Competition"},
    {"CUZ",   "because"},
    {"TY",    "thank-you"},
    {"YW",    "you're welcome"},
    {"TTYL",  "talk to you later"}
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

    for (string word; cin >> word; )
    {
        cout << (translations.count(word) ? translations.at(word) : word) << '\n';
    }

    return 0;
}
