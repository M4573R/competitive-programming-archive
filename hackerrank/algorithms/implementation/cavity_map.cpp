#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char cavity {'X'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline bool is_cavity(const vector<string>& map, unsigned int i, unsigned int j)
{
    return (map[i][j] > map[i - 1][j] && map[i][j] > map[i + 1][j] &&
            map[i][j] > map[i][j - 1] && map[i][j] > map[i][j + 1]);
}

int main()
{
    use_io_optimizations();

    unsigned int map_size;
    cin >> map_size;

    vector<string> map(map_size);

    for (auto& row : map)
    {
        cin >> row;
    }

    for (unsigned int i {1}; i < map_size - 1; ++i)
    {
        for (unsigned int j {1}; j < map_size - 1; ++j)
        {
            if (is_cavity(map, i, j))
            {
                map[i][j] = cavity;
            }
        }
    }

    for (const auto& row : map)
    {
        cout << row << '\n';
    }

    return 0;
}
