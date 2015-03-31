#include <cctype>
#include <iostream>
#include <map>

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

    unsigned int rooms;
    cin >> rooms;

    unsigned int bought_keys {0};
    map<char, unsigned int> keys_count;

    for (unsigned int i {0}; i < rooms - 1; ++i)
    {
        char key;
        char door;

        cin >> key >> door;

        ++keys_count[key];

        if (keys_count[tolower(door)] == 0)
        {
            ++bought_keys;
        }
        else
        {
            --keys_count[tolower(door)];
        }
    }

    cout << bought_keys << '\n';

    return 0;
}
