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

    unsigned int magnets;
    cin >> magnets;

    unsigned int groups {1};

    string current;
    cin >> current;

    for (unsigned int i {1}; i < magnets; ++i)
    {
        string next;
        cin >> next;

        if (next[0] == current[1])
        {
            ++groups;
        }

        current = next;
    }

    cout << groups << '\n';

    return 0;
}
