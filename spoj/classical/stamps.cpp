#include <algorithm>
#include <functional>
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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int needed;
        unsigned int friends;

        cin >> needed >> friends;

        vector<unsigned int> offers(friends);

        for (auto& offer : offers)
        {
            cin >> offer;
        }

        sort(offers.begin(), offers.end(), greater<unsigned int>());

        unsigned int borrowed {0};

        while (borrowed < friends && needed > 0)
        {
            needed -= min(needed, offers[borrowed++]);
        }

        cout << "Scenario #" << test << ":\n";

        if (needed == 0)
        {
            cout << borrowed << "\n\n";
        }
        else
        {
            cout << "impossible\n\n";
        }
    }

    return 0;
}
