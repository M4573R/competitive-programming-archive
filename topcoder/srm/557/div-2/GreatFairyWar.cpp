#include <vector>

using namespace std;

class GreatFairyWar
{
public:
    int minHP(vector<int> dps, vector<int> hp)
    {
        int damage  = 0;
        int seconds = 0;

        for (int i = 0; i < hp.size(); ++i)
        {
            seconds += hp[i];
            damage  += seconds * dps[i];
        }

        return damage;
    }
};
