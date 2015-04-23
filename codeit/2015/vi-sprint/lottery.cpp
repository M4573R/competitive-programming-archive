#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<unsigned int> topsort(const vector< vector<unsigned int> >& graph,
                             vector<unsigned int>& in_degrees,
                             unsigned int upper_limit)
{
    vector<unsigned int> sorted;
    queue <unsigned int> remaining;

    for (unsigned int i = 1; i <= upper_limit; ++i)
    {
        if (in_degrees[i] == 0)
        {
            remaining.push(i);
        }
    }

    while (!remaining.empty())
    {
        unsigned int current = remaining.front();
        remaining.pop();

        sorted.push_back(current);

        for (unsigned int i = 0; i < graph[current].size(); ++i)
        {
            unsigned int adjacent = graph[current][i];

            if (--in_degrees[adjacent] == 0)
            {
                remaining.push(adjacent);
            }
        }
    }

    return sorted;
}

int main()
{
    freopen("lottery.in",  "r", stdin);
    freopen("lottery.out", "w", stdout);

    unsigned int hints;
    cin >> hints;

    unsigned int upper_limit = 1;
    vector<unsigned int> in_degrees(401);
    vector< vector<unsigned int> > graph(401);

    for (unsigned int i = 0; i < hints; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        ++in_degrees[to];
        graph[from].push_back(to);

        upper_limit = max(upper_limit, max(from, to));
    }

    vector<unsigned int> sorted = topsort(graph, in_degrees, upper_limit);

    for (unsigned int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << (i < sorted.size() - 1 ? ' ' : '\n');
    }

    return 0;
}
