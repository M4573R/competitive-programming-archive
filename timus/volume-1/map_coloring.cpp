#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using Node          = unsigned int;
using AdjacencyList = vector<set<Node>>;

enum class Color
{
    Red, Blue, None
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline Color opposite_color(Color color)
{
    return color == Color::Red ? Color::Blue : Color::Red;
}

bool is_bipartite(const AdjacencyList& graph, vector<Color>& coloring)
{
    vector<Node> visited(graph.size(), false);

    queue<Node> levels;
    levels.push(1);

    visited[1]  = true;
    coloring[1] = Color::Red;

    while (!levels.empty())
    {
        Node current {levels.front()};
        levels.pop();

        for (Node adjacent : graph[current])
        {
            if (!visited[adjacent])
            {
                levels.push(adjacent);

                visited[adjacent]  = true;
                coloring[adjacent] = opposite_color(coloring[current]);
            }
            else
            {
                if (coloring[current] == coloring[adjacent])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int nodes;
    cin >> nodes;

    AdjacencyList graph(nodes + 1);

    for (unsigned int i {1}; i <= nodes; ++i)
    {
        Node source  {i};
        Node destination;

        while (cin >> destination && destination != 0)
        {
            graph[source].insert(destination);
            graph[destination].insert(source);
        }
    }

    vector<Color> coloring(nodes + 1, Color::None);

    if (is_bipartite(graph, coloring))
    {
        for (Color color : coloring)
        {
            switch (color)
            {
            case Color::Red:
                cout << 0;
                break;

            case Color::Blue:
                cout << 1;
                break;
            }
        }
    }
    else
    {
        cout << -1;
    }

    cout << '\n';

    return 0;
}
