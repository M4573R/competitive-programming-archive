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

    unsigned int badges;
    cin >> badges;

    vector<unsigned int> factors(badges);

    for (auto& factor : factors)
    {
        cin >> factor;
    }

    sort(factors.begin(), factors.end());

    unsigned int coins {0};

    for (unsigned int i {0}; i < badges - 1; ++i)
    {
        if (factors[i] >= factors[i + 1])
        {
            coins          += factors[i] - factors[i + 1] + 1;
            factors[i + 1]  = factors[i] + 1;
        }
    }

    cout << coins << '\n';

    return 0;
}
