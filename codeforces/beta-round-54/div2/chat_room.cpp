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
        if (matches < greeting.size() && symbol == greeting[matches])
        {
            ++matches;
        }
    }

    cout << (matches == greeting.size() ? "YES" : "NO") << '\n';

    return 0;
}
