#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int shop(int garments, int money, const vector<vector<int>>& prices)
{
    vector<vector<int>> subtasks(garments + 1, vector<int>(money + 1, -1));

    for (int i {0}; i <= money; ++i)
    {
        subtasks[0][i] = 0;
    }

    for (int i {1}; i <= garments; ++i)
    {
        for (auto price : prices[i - 1])
        {
            for (int j {0}; j <= money; ++j)
            {
                if (j >= price && subtasks[i - 1][j - price] != -1)
                {
                    subtasks[i][j] = max(subtasks[i][j],
                                         subtasks[i - 1][j - price] + price);
                }
            }
        }
    }

    return subtasks[garments][money];
}

int main()
{
    use_io_optimizations();

    int test_cases;
    cin >> test_cases;

    for (int i {0}; i < test_cases; ++i)
    {
        int money;
        int garments;

        cin >> money >> garments;

        vector<vector<int>> prices(garments);

        for (auto& garment_prices : prices)
        {
            int models;
            cin >> models;

            garment_prices.resize(models);

            for (auto& price : garment_prices)
            {
                cin >> price;
            }
        }

        int max_spent_money {shop(garments, money, prices)};

        if (max_spent_money < 0)
        {
            cout << "no solution";
        }
        else
        {
            cout << max_spent_money;
        }

        cout << '\n';
    }

    return 0;
}
