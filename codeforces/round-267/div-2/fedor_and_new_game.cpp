#include <iostream>
#include <vector>

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

    unsigned int soldiers;
    unsigned int players;
    unsigned int max_difference;

    cin >> soldiers >> players >> max_difference;

    vector<unsigned int> armies(players + 1);

    for (auto& army : armies)
    {
        cin >> army;
    }

    unsigned int friends {0};

    for (unsigned int i {0}; i < players; ++i)
    {
        if (__builtin_popcount(armies[i] ^ armies.back()) <= max_difference)
        {
            ++friends;
        }
    }

    cout << friends << '\n';

    return 0;
}
