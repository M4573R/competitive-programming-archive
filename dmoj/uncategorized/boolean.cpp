#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<string, string> oppisites {{"True",  "False"},
                                     {"False", "True"}};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string value;
    unsigned int negations {0};

    while (cin >> value && value == "not")
    {
        ++negations;
    }

    cout << (negations % 2 ? oppisites.at(value) : value) << '\n';

    return 0;
}
