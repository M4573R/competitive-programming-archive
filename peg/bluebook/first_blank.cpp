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

    unsigned int test_cases;
    cin >> test_cases;
    cin.ignore();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string line;
        getline(cin, line);

        auto position = line.find(' ');

        cout << (position == string::npos ? 0 : position + 1) << '\n';
    }

    return 0;
}
