#include <queue>
#include <set>
#include <vector>

using namespace std;

class NarrowPassage2Easy
{
public:
    int count(vector<int> size, int maxSizeSum)
    {
        vector<int> initial_node(size.size());

        for (vector<int>::size_type i {0}; i < initial_node.size(); ++i)
        {
            initial_node[i] = i;
        }

        return traverse(initial_node, size, maxSizeSum);
    }

    int traverse(const vector<int>& initial_node,
                 const vector<int>& size,
                 int maxSizeSum)
    {
        set<vector<int>> visited;
        visited.insert(initial_node);

        queue<vector<int>> levels;
        levels.push(initial_node);

        while (!levels.empty())
        {
            vector<int> node {levels.front()};
            levels.pop();

            for (vector<int>::size_type i {0}; i < node.size() - 1; ++i)
            {
                if (size[node[i]] + size[node[i + 1]] <= maxSizeSum)
                {
                    vector<int> adjacent {node};
                    swap(adjacent[i], adjacent[i + 1]);

                    if (!visited.count(adjacent))
                    {
                        visited.insert(adjacent);
                        levels.push(adjacent);
                    }
                }
            }
        }

        return visited.size();
    }
};
