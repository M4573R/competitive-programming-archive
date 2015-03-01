#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class PriceCalculator
{
public:
    PriceCalculator(const vector<pair<unsigned int, double>>& prices):
        prices(prices),
        computed(prices.size(), vector<double>(101, -1))
    { }

    double price(int items)
    {
        return calculate(0, items);
    }

private:
    vector<pair<unsigned int, double>> prices;
    vector<vector<double>> computed;

    double calculate(unsigned int index, int items)
    {
        if (items <= 0)
        {
            return 0;
        }

        if (index == prices.size())
        {
            return numeric_limits<double>::infinity();
        }

        if (computed[index][items] != -1)
        {
            return computed[index][items];
        }

        unsigned int count {prices[index].first};
        double       cost  {prices[index].second};

        return computed[index][items] = min(calculate(index + 1, items),
                                            calculate(index, items - count) + cost);
    }
};

int main()
{
    use_io_optimizations();

    cout << fixed << setprecision(2);

    double unit_price;
    unsigned int offers;

    for (unsigned int test {1}; cin >> unit_price >> offers; ++test)
    {
        vector<pair<unsigned int, double>> prices(offers + 1);
        prices[0] = make_pair(1, unit_price);

        for (unsigned int i {1}; i <= offers; ++i)
        {
            cin >> prices[i].first >> prices[i].second;
        }

        cin.ignore();

        string line;
        getline(cin, line);

        istringstream in {line};
        PriceCalculator calculator {prices};

        cout << "Case " << test << ":\n";

        for (unsigned int items; in >> items; )
        {
            cout << "Buy " << items << " for $" << calculator.price(items) << '\n';
        }
    }

    return 0;
}
