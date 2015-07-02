#include <iostream>
#include <unordered_map>

using namespace std;

constexpr unsigned int people {5};

const unordered_map<unsigned int, string> names {
    {0, "Sheldon"},
    {1, "Leonard"},
    {2, "Penny"},
    {3, "Rajesh"},
    {4, "Howard"}
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int position;
    cin >> position;

    unsigned int iteration {1};

    for (; position > iteration * people; iteration *= 2)
    {
        position -= iteration * people;
    }

    cout << names.at((position + iteration - 1) / iteration - 1) << '\n';

    return 0;
}
