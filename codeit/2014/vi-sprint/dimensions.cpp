#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

const int infinity = numeric_limits<int>::max();

struct Stone
{
    int x;
    int y;
    int z;
};

bool operator==(const Stone& left, const Stone& right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

istream& operator>>(istream& in, Stone& Stone)
{
    return in >> Stone.x >> Stone.y >> Stone.z;
}

ostream& operator<<(ostream& out, const Stone& Stone)
{
    return out << Stone.x << ' ' << Stone.y << ' ' << Stone.z;
}

int distance2(const Stone& left, const Stone& right)
{
    if (left.z != right.z)
    {
        if (left.x == right.x && left.y == right.y)
        {
            return 1;
        }

        return infinity;
    }

    return ((left.x - right.x) * (left.x - right.x) +
            (left.y - right.y) * (left.y - right.y));
}

struct Edge
{
    int node;
    double weight;

    Edge(int node, double weight):
        node(node),
        weight(weight)
    { }
};

bool operator<(const Edge& left, const Edge& right)
{
    return left.weight > right.weight;
}

void read_input(int& dimensions,
                int& jump_length,
                int& stones_count,
                vector<Stone>& stones,
                Stone& start,
                Stone& end)
{
    cin >> dimensions >> jump_length >> stones_count;

    stones.resize(stones_count);

    for (int i = 0; i < stones_count; ++i)
    {
        cin >> stones[i];
    }

    cin >> start >> end;
}

void find_indices(const vector<Stone>& stones,
                  const Stone& start,
                  const Stone& end,
                  int& start_index,
                  int& end_index)
{
    for (int i = 0; i < stones.size(); ++i)
    {
        if (stones[i] == start)
        {
            start_index = i;
        }
        else if (stones[i] == end)
        {
            end_index = i;
        }
    }
}

void build_graph(const vector<Stone>& stones,
                 int jump_length,
                 vector< vector<Edge> >& graph)
{
    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = i + 1; j < graph.size(); ++j)
        {
            int dist2 = distance2(stones[i], stones[j]);

            if (dist2 <= jump_length * jump_length)
            {
                double dist = sqrt(dist2);

                graph[i].push_back(Edge(j, dist));
                graph[j].push_back(Edge(i, dist));
            }
        }
    }
}

void dijkstra(const vector< vector<Edge> >& graph,
              int start,
              int end,
              vector<double>& distances,
              vector<int>& parents)
{
    priority_queue<Edge> cut;

    distances[start] = 0;
    cut.push(Edge(start, 0));

    while (!cut.empty())
    {
        int node        = cut.top().node;
        double distance = cut.top().weight;
        cut.pop();

        if (distances[node] < distance)
        {
            continue;
        }

        for (int i = 0; i < graph[node].size(); ++i)
        {
            int adjacent  = graph[node][i].node;
            double weight = graph[node][i].weight;

            if (distance + weight < distances[adjacent])
            {
                distances[adjacent] = distance + weight;
                parents[adjacent]   = node;
                cut.push(Edge(adjacent, distances[adjacent]));
            }
        }
    }
}

void find_shortest_path(const vector< vector<Edge> >& graph,
                        const vector<Stone>& stones,
                        int start_index,
                        int end_index)
{
    vector<double> distances(graph.size(), infinity);
    vector<int>    parents(graph.size(), -1);

    dijkstra(graph, start_index, end_index, distances, parents);

    if (distances[end_index] >= infinity)
    {
        cout << "0\n";
    }
    else
    {
        deque<int> shortest_path;

        for (int node = end_index; node != -1; node = parents[node])
        {
            shortest_path.push_front(node);
        }

        cout << shortest_path.size() << '\n';

        for (int i = 0; i < shortest_path.size(); ++i)
        {
            cout << stones[shortest_path[i]] << '\n';
        }
    }
}

int main()
{
    freopen("dimensions.in",  "r", stdin);
    freopen("dimensions.out", "w", stdout);

    int dimensions;
    int jump_length;
    int stones_count;

    vector<Stone> stones;

    Stone start;
    Stone end;

    read_input(dimensions, jump_length, stones_count, stones, start, end);

    int start_index;
    int end_index;

    find_indices(stones, start, end, start_index, end_index);

    vector< vector<Edge> > graph(stones_count);

    build_graph(stones, jump_length, graph);

    find_shortest_path(graph, stones, start_index, end_index);

    return 0;
}
