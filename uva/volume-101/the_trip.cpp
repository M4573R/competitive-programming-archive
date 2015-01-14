#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int students;

    while (cin >> students && students != 0)
    {
        vector<double> expenses(students);

        for (auto& amount : expenses)
        {
            cin >> amount;
        }

        sort(expenses.begin(), expenses.end());

        double total_spent    {accumulate(expenses.begin(), expenses.end(), 0.0)};
        double total_in_cents {total_spent * 100};

        double lower_limit {floor(total_in_cents / students) / 100};
        double upper_limit {ceil(total_in_cents  / students) / 100};

        double to_receive {0};
        double to_give    {0};

        for (double amount : expenses)
        {
            if (amount < lower_limit)
            {
                to_receive += lower_limit - amount;
            }
            else if (amount > upper_limit)
            {
                to_give += amount - upper_limit;
            }
        }

        cout << fixed << setprecision(2)
             << "$"   << max(to_receive, to_give) << '\n';
    }

    return 0;
}
