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

int main()
{
    use_io_optimizations();

    unsigned int days;
    unsigned int payment;

    cin >> days >> payment;

    vector<unsigned int> prices(days);

    for (auto& price : prices)
    {
        cin >> price;
    }

    unsigned int max_gain {0};

    for (unsigned int i {0}; i < days - 1; ++i)
    {
        if (prices[i] >= prices[i + 1] + payment)
        {
            max_gain = max(max_gain, prices[i] - prices[i + 1] - payment);
        }
    }

    cout << max_gain << '\n';

    return 0;
}
