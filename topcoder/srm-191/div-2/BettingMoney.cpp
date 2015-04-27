#include <vector>

using namespace std;

class BettingMoney
{
public:
    int moneyMade(vector<int> amounts, vector<int> centsPerDollar, int finalResult)
    {
        int net_gain {0};

        for (int i = 0; i < amounts.size(); ++i)
        {
            if (i == finalResult)
            {
                net_gain -= amounts[i] * centsPerDollar[i];
            }
            else
            {
                net_gain += amounts[i] * 100;
            }
        }

        return net_gain;
    }
};
