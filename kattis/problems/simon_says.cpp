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

    for (unsigned test {0}; test < test_cases; ++test)
    {
        string line;
        getline(cin, line);

        if (line.substr(0, 10) == "simon says" && line.size() > 10)
        {
            cout << line.substr(11);
        }

        cout << '\n';
    }

    return 0;
}
