#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Teams
{
public:
    Teams(const vector<unsigned int>& abilities):
        contestants(abilities.size()),
        abilities(abilities),
        computed(1 << contestants, -1)
    { }

    unsigned int count()
    {
        return count(0);
    }

    unsigned int count(unsigned int mask)
    {
        if (computed[mask] != -1)
        {
            return computed[mask];
        }

        unsigned int teams {0};
        bool found_team    {false};

        unsigned int x {0};

        for (; x < contestants && (mask & (1 << x)); ++x)
        { }

        for (unsigned int y {x + 1}; y < contestants; ++y)
        {
            if (!(mask & (1 << y)))
            {
                for (unsigned int z {y + 1}; z < contestants; ++z)
                {
                    if (!(mask & (1 << z)) &&
                        (abilities[x] + abilities[y] + abilities[z] >= 20))
                    {
                        teams = max(teams, count(mask     |
                                                 (1 << x) |
                                                 (1 << y) |
                                                 (1 << z)));
                        found_team = true;
                    }
                }
            }
        }

        return computed[mask] = teams + found_team;
    }

private:
    unsigned int contestants;

    vector<unsigned int> abilities;
    vector<unsigned int> computed;
};

int main()
{
    use_io_optimizations();

    unsigned int contestants;

    for (unsigned int test {1}; cin >> contestants && contestants != 0; ++test)
    {
        vector<unsigned int> abilities(contestants);

        for (auto& ability : abilities)
        {
            cin >> ability;
        }

        cout << "Case " << test << ": " << Teams{abilities}.count() << '\n';
    }

    return 0;
}
