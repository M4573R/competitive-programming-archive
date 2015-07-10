#include <algorithm>
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

    unsigned int disks;
    cin >> disks;

    string initial;
    string key;

    cin >> initial >> key;

    unsigned int min_moves {0};

    for (unsigned int i {0}; i < disks; ++i)
    {
        min_moves += min(abs(initial[i] - key[i]),
                         abs(10 - abs(initial[i] - key[i])));
    }

    cout << min_moves << '\n';

    return 0;
}
