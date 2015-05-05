#include <algorithm>
#include <vector>

using namespace std;

class IncubatorEasy
{
public:
    int maxMagicalGirls(vector<string> love)
    {
        int girls = love.size();

        for (int k = 0; k < girls; ++k)
        {
            for (int i = 0; i < girls; ++i)
            {
                for (int j = 0; j < girls; ++j)
                {
                    if (love[i][k] == 'Y' && love[k][j] == 'Y')
                    {
                        love[i][j] = 'Y';
                    }
                }
            }
        }

        int max_magical = 0;

        for (int subset = 0; subset < (1 << girls); ++subset)
        {
            max_magical = max(max_magical, count_magical(love, subset));
        }

        return max_magical;
    }

private:
    int count_magical(const vector<string>& love, int subset)
    {
        int girls = love.size();

        vector<bool> is_magical(girls);
        vector<bool> is_protected(girls);

        for (int i = 0; i < girls; ++i)
        {
            if (subset & (1 << i))
            {
                is_magical[i] = true;
            }
        }

        for (int i = 0; i < girls; ++i)
        {
            if (is_magical[i])
            {
                for (int j = 0; j < girls; ++j)
                {
                    if (love[i][j] == 'Y')
                    {
                        is_protected[j] = true;
                    }
                }
            }
        }

        int magical = 0;

        for (int i = 0; i < girls; ++i)
        {
            if (is_magical[i] && !is_protected[i])
            {
                ++magical;
            }
        }

        return magical;
    }
};
