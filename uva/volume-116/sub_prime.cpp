#include <iostream>
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

    unsigned int banks;
    unsigned int debentures;

    while (cin >> banks >> debentures && !(banks == 0 && debentures == 0))
    {
        vector<int> reserves(banks);

        for (auto& reserve : reserves)
        {
            cin >> reserve;
        }

        for (unsigned int i {0}; i < debentures; ++i)
        {
            unsigned int deptor;
            unsigned int creditor;
            unsigned int value;

            cin >> deptor >> creditor >> value;

            reserves[deptor   - 1] -= value;
            reserves[creditor - 1] += value;
        }

        bool can_liquidate_debentures {true};

        for (auto reserve : reserves)
        {
            if (reserve < 0)
            {
                can_liquidate_debentures = false;
            }
        }

        cout << (can_liquidate_debentures ? 'S' : 'N') << '\n';
    }

    return 0;
}
