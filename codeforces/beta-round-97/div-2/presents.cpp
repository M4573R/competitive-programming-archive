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

    unsigned int friends;
    cin >> friends;

    vector<unsigned int> givers(friends + 1);

    for (unsigned int i {1}; i <= friends; ++i)
    {
        unsigned int receiver;
        cin >> receiver;

        givers[receiver] = i;
    }

    for (unsigned int i {1}; i <= friends; ++i)
    {
        cout << givers[i] << (i < friends ? ' ' : '\n');
    }

    return 0;
}
