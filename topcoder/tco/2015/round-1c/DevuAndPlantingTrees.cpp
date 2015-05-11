#include <string>
#include <vector>

using namespace std;

class DevuAndPlantingTrees
{
public:
    int maximumTreesDevuCanGrow(vector<string> garden)
    {
        int columns = garden.front().size();
        vector<bool> is_free(columns, true);

        int trees {0};

        for (int i {0}; i < columns; ++i)
        {
            if (garden[0][i] == '*' || garden[1][i] == '*')
            {
                ++trees;
                is_free[i] = false;
            }
        }

        for (int i {0}; i < columns; ++i)
        {
            if (is_free[i] &&
                (i == 0 || is_free[i - 1]) &&
                (i == columns - 1 || is_free[i + 1]))
            {
                ++trees;
                is_free[i] = false;
            }
        }

        return trees;
    }
};
