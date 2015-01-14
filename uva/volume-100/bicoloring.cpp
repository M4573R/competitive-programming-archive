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

bool is_bipartite(const AdjacencyList& graph)
{
    vector<Node>  visited(graph.size(), false);
    vector<Color> coloring(graph.size(), Color::None);

    queue<Node> levels;
    levels.push(0);

    visited[0]  = true;
    coloring[0] = Color::Red;

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
    unsigned int edges;

    while (cin >> nodes >> edges && nodes != 0)
    {
        AdjacencyList graph(nodes);

        for (unsigned int i {0}; i < edges; ++i)
        {
            Node source;
            Node destination;

            cin >> source >> destination;

            graph[source].insert(destination);
            graph[destination].insert(source);
        }

        cout << (is_bipartite(graph) ? "BICOLORABLE." : "NOT BICOLORABLE.")
             << '\n';
    }

    return 0;
}
