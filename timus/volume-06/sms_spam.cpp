#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const unordered_map<char, unsigned int> characters_costs {
    {'a', 1}, {'b', 2}, {'c', 3},
    {'d', 1}, {'e', 2}, {'f', 3},
    {'g', 1}, {'h', 2}, {'i', 3},
    {'j', 1}, {'k', 2}, {'l', 3},
    {'m', 1}, {'n', 2}, {'o', 3},
    {'p', 1}, {'q', 2}, {'r', 3},
    {'s', 1}, {'t', 2}, {'u', 3},
    {'v', 1}, {'w', 2}, {'x', 3},
    {'y', 1}, {'z', 2},
    {'.', 1}, {',', 2}, {'!', 3},
    {' ', 1}
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string slogan;
    getline(cin, slogan);

    unsigned int cost {0};

    for (auto character : slogan)
    {
        cost += characters_costs.at(character);
    }

    cout << cost << '\n';

    return 0;
}
