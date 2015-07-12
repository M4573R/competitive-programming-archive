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

    unsigned int sellers;
    unsigned int money;

    cin >> sellers >> money;

    vector<unsigned int> deals;

    for (unsigned int i {1}; i <= sellers; ++i)
    {
        unsigned int items;
        cin >> items;

        unsigned int min_price {1000000};

        for (unsigned int j {0}; j < items; ++j)
        {
            unsigned int price;
            cin >> price;

            min_price = min(min_price, price);
        }

        if (min_price < money)
        {
            deals.push_back(i);
        }
    }

    cout << deals.size() << '\n';

    for (unsigned int i {0}; i < deals.size(); ++i)
    {
        cout << deals[i] << (i + 1 < deals.size() ? ' ' : '\n');
    }

    return 0;
}
