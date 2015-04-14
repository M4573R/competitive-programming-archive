#include <iostream>
#include <queue>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void traverse(unsigned int from,
              const vector<vector<unsigned int>>& links,
              vector<vector<int>>& distances)
{
    distances[from][from] = 0;

    queue<unsigned int> levels;
    levels.push(from);

    while (!levels.empty())
    {
        unsigned int current {levels.front()};
        levels.pop();

        for (auto adjacent : links[current])
        {
            if (distances[from][adjacent] == -1)
            {
                distances[from][adjacent] = distances[from][current] + 1;
                levels.push(adjacent);
            }
        }
    }
}

vector<vector<int>> room_distances(unsigned int rooms,
                                   const vector<vector<unsigned int>>& links)
{
    vector<vector<int>> distances(rooms + 1, vector<int>(rooms + 1, -1));

    for (unsigned int i {1}; i <= rooms; ++i)
    {
        traverse(i, links, distances);
    }

    return distances;
}

int main()
{
    use_io_optimizations();

    unsigned int rooms;
    unsigned int hallways;
    unsigned int traverse_time;

    cin >> rooms >> hallways >> traverse_time;

    vector<vector<unsigned int>> links(rooms + 1);

    for (unsigned int i {0}; i < hallways; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        links[from].push_back(to);
    }

    vector<vector<int>> distances {room_distances(rooms, links)};

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        if (distances[from][to] == -1)
        {
            cout << "Not enough hallways!";
        }
        else
        {
            cout << distances[from][to] * traverse_time;
        }

        cout << '\n';
    }

    return 0;
}
