#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef string                 Node;
typedef set<Node>::iterator    NodesIterator;
typedef vector<Node>::iterator SuccessorsIterator;

enum Color
{
    White,
    Gray,
    Black
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool traverse(const Node& node,
              map<Node, vector<Node> >& graph,
              map<Node, Color>& colors)
{
    colors[node] = Gray;

    for (SuccessorsIterator i = graph[node].begin(); i != graph[node].end(); ++i)
    {
        if (colors[*i] == Gray)
        {
            return true;
        }
        else if (colors[*i] == White)
        {
            if (traverse(*i, graph, colors))
            {
                return true;
            }
        }
    }

    colors[node] = Black;

    return false;
}

bool has_cycles(map<Node, vector<Node> >& graph,
                set<Node>& nodes)
{
    map<Node, Color> colors;

    for (NodesIterator i = nodes.begin(); i != nodes.end(); ++i)
    {
        if (colors[*i] == White)
        {
            if (traverse(*i, graph, colors))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int nodes_count;
        cin >> nodes_count;

        set<Node> nodes;
        map<Node, vector<Node> > graph;

        for (unsigned int i = 0; i < nodes_count; ++i)
        {
            Node from;
            Node to;

            cin >> from >> to;

            nodes.insert(from);
            nodes.insert(to);

            graph[from].push_back(to);
        }

        cout << "Case " << test << ": "
            << (has_cycles(graph, nodes) ? "No" : "Yes") << '\n';
    }

    return 0;
}
