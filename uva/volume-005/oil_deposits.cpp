#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using AdjacencyList = map<unsigned int, vector<unsigned int>>;

constexpr char pocket {'@'};
constexpr char blank  {'*'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline vector<pair<unsigned int, unsigned int>> adjacent_plots(unsigned int x,
                                                               unsigned int y)
{
    return {{x - 1, y - 1},
            {x - 1, y    },
            {x - 1, y + 1},
            {x,     y - 1},
            {x,     y + 1},
            {x + 1, y - 1},
            {x + 1, y    },
            {x + 1, y + 1}};
}

inline unsigned int coordinates_to_node(unsigned int x,
                                        unsigned int y,
                                        unsigned int columns)
{
    return (x - 1) * columns + y - 1;
}

void breadth_first_traversal(const AdjacencyList& graph,
                             vector<bool>& visited,
                             unsigned int start_node)
{
    queue<unsigned int> levels;
    levels.push(start_node);

    while (!levels.empty())
    {
        unsigned int current_node {levels.front()};
        levels.pop();

        visited[current_node] = true;

        for (auto adjacent_node : graph.at(current_node))
        {
            if (!visited[adjacent_node])
            {
                levels.push(adjacent_node);
            }
        }
    }
}

unsigned int connected_components(const AdjacencyList& graph, unsigned int nodes)
{
    vector<bool> visited(nodes);

    unsigned int components {0};

    for (auto& node_and_adjacent : graph)
    {
        unsigned int node {node_and_adjacent.first};

        if (!visited[node])
        {
            ++components;
            breadth_first_traversal(graph, visited, node);
        }
    }

    return components;
}

int main()
{
    use_io_optimizations();

    unsigned int rows;
    unsigned int columns;

    while (cin >> rows >> columns && !(rows == 0 & columns == 0))
    {
        AdjacencyList graph;

        vector<vector<char>> grid(rows + 2, vector<char>(columns + 2, blank));

        for (unsigned int i {1}; i <= rows; ++i)
        {
            for (unsigned int j {1}; j <= columns; ++j)
            {
                cin >> grid[i][j];

                if (grid[i][j] != pocket)
                {
                    continue;
                }

                unsigned int current_node {coordinates_to_node(i, j, columns)};
                graph[current_node] = {};

                for (auto& plot : adjacent_plots(i, j))
                {
                    unsigned int x {plot.first};
                    unsigned int y {plot.second};

                    unsigned int adjacent_node {coordinates_to_node(x, y, columns)};

                    if (grid[x][y] == pocket)
                    {
                        graph[current_node].push_back(adjacent_node);
                        graph[adjacent_node].push_back(current_node);
                    }
                }
            }
        }

        cout << connected_components(graph, rows * columns) << '\n';
    }

    return 0;
}
