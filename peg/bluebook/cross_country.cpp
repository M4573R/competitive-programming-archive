#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, string> descriptions {
    {"MG", "midget girls"},
    {"MB", "midget boys"},
    {"JG", "junior girls"},
    {"JB", "junior boys"},
    {"SG", "senior gilrs"},
    {"SB", "senior boys"}
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

    string code;
    cin >> code;

    if (descriptions.count(code))
    {
        cout << descriptions.at(code);
    }
    else
    {
        cout << "invalid code";
    }

    cout << '\n';

    return 0;
}
