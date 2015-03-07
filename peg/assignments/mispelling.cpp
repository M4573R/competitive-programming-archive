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

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int index;
        cin >> index;
        cin.ignore();

        string line;
        getline(cin, line);
        line.erase(index - 1, 1);

        cout << test << ' ' << line << '\n';
    }

    return 0;
}
