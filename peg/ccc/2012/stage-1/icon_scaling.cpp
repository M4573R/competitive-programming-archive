#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> icon {
    "*x*",
    " xx",
    "* *"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string scale_line(const string& line, unsigned int factor)
{
    string scaled;

    for (auto& symbol : line)
    {
        scaled += string(factor, symbol);
    }

    return scaled;
}

int main()
{
    use_io_optimizations();

    unsigned int factor;
    cin >> factor;

    for (auto& line : icon)
    {
        string scaled {scale_line(line, factor)};

        for (unsigned int i {0}; i < factor; ++i)
        {
            cout << scaled << '\n';
        }
    }

    return 0;
}
