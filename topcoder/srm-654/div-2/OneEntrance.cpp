#include <algorithm>
#include <vector>

using namespace std;

class OneEntrance
{
private:
    int vertices;

    vector<vector<int>> graph;
    vector<int> initial_degrees;
    vector<int> order;

    void initialize(vector<int> sources, vector<int> destinations, int root)
    {
        vertices = sources.size() + 1;

        graph.resize(vertices);
        initial_degrees.resize(vertices);

        ++initial_degrees[root];

        for (vector<int>::size_type i {0}; i < sources.size(); ++i)
        {
            graph[sources[i]].push_back(destinations[i]);
            graph[destinations[i]].push_back(sources[i]);

            ++initial_degrees[sources[i]];
            ++initial_degrees[destinations[i]];
        }

        order.resize(vertices);

        for (int i {0}; i < vertices; ++i)
        {
            order[i] = i;
        }
    }

public:
    int count(vector<int> sources, vector<int> destinations, int root)
    {
        initialize(sources, destinations, root);

        int arrangements {0};

        do
        {
            bool is_correct     {true};
            vector<int> degrees {initial_degrees};

            for (int i {0}; i < vertices && is_correct; ++i)
            {
                if (degrees[order[i]] > 1)
                {
                    is_correct = false;
                }

                for (auto adjacent : graph[order[i]])
                {
                    --degrees[adjacent];
                }
            }

            arrangements += is_correct;

        } while (next_permutation(order.begin(), order.end()));

        return arrangements;
    }
};
