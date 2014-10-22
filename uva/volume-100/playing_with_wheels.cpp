#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using Node = vector<unsigned int>;

constexpr unsigned int wheel_size {9};
constexpr unsigned int wheels     {4};

istream& operator>>(istream& input_stream, Node& node)
{
    for (Node::size_type i {0}; i < node.size(); ++i)
    {
        input_stream >> node[i];
    }

    return input_stream;
}

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline unsigned int next(unsigned int n)
{
    return (n + 1) % (wheel_size + 1);
}

inline unsigned int previous(unsigned int n)
{
    return n == 0 ? wheel_size : n - 1;
}

vector<Node> adjacent_nodes(const Node& node)
{
    vector<Node> adjacent(2 * node.size(), node);

    for (Node::size_type i {0}; i < node.size(); ++i)
    {
        adjacent[2 * i][i]     = previous(adjacent[2 * i][i]);
        adjacent[2 * i + 1][i] = next(adjacent[2 * i + 1][i]);
    }

    return adjacent;
}

int min_button_presses(const Node& initial,
                       const Node& target,
                       const set<Node>& forbidden)
{
    if (initial == target)
    {
        return 0;
    }

    set<Node> visited(forbidden);
    visited.insert(initial);

    queue<Node> levels;
    levels.push(initial);

    map<Node, int> button_presses;
    button_presses[initial] = 0;

    while (!levels.empty())
    {
        Node current {levels.front()};
        levels.pop();

        for (Node adjacent : adjacent_nodes(current))
        {
            if (adjacent == target)
            {
                return button_presses[current] + 1;
            }

            if (visited.find(adjacent) == visited.end())
            {
                levels.push(adjacent);
                visited.insert(adjacent);
                button_presses[adjacent] = button_presses[current] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        Node initial(wheels);
        cin >> initial;

        Node target(wheels);
        cin >> target;

        unsigned int forbidden_count;
        cin >> forbidden_count;

        set<Node> forbidden;

        for (unsigned int j {0}; j < forbidden_count; ++j)
        {
            Node node(wheels);
            cin >> node;

            forbidden.insert(node);
        }

        cout << min_button_presses(initial, target, forbidden) << '\n';
    }

    return 0;
}
