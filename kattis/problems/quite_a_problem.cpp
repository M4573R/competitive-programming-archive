#include <algorithm>
#include <cctype>
#include <iostream>
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

    for (string line; getline(cin, line); )
    {
        transform(line.begin(), line.end(), line.begin(), ::tolower);

        cout << (line.find("problem") != string::npos ? "yes" : "no") << '\n';
    }

    return 0;
}
