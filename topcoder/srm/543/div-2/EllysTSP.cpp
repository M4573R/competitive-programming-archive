#include <algorithm>

using namespace std;

class EllysTSP
{
public:
    int getMax(string places)
    {
        int villages {0};
        int cities   {0};

        for (auto symbol : places)
        {
            if (symbol == 'V')
            {
                ++villages;
            }
            else
            {
                ++cities;
            }
        }

        int fewer {min(villages, cities)};

        return villages == cities ? 2 * fewer : 2 * fewer + 1;
    }
};
