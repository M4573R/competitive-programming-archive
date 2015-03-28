#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> amounts {
    100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int opened;
    cin >> opened;

    unsigned int money_left {1691600};

    for (unsigned int i {0}; i < opened; ++i)
    {
        unsigned int briefcase;
        cin >> briefcase;

        money_left -= amounts[briefcase - 1];
    }

    unsigned int offer;
    cin >> offer;

    cout << (offer > money_left / (10.0 - opened) ? "deal" : "no deal") << '\n';

    return 0;
}
