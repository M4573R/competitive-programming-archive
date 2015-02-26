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

    string greeting {"hello"};

    string word;
    cin >> word;

    unsigned int matches {0};

    for (auto symbol : word)
    {
        if (symbol == greeting[matches])
        {
            ++matches;
        }

        if (matches == 5)
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
