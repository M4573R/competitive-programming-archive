#include <algorithm>
#include <vector>

using namespace std;

class UnrelatedPaths
{
public:
    int maxUnrelatedPaths(vector<int> parent)
    {
        vector<bool> is_leaf(parent.size() + 1, true);

        for (int i {0}; i < parent.size(); ++i)
        {
            is_leaf[parent[i]] = false;
        }

        return count(is_leaf.cbegin(), is_leaf.cend(), true);
    }
};
