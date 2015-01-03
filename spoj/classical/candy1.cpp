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

    for (int packets; cin >> packets && packets != -1;)
    {
        int total_candies {0};
        vector<int> candies_per_packet(packets);

        for (auto& candies : candies_per_packet)
        {
            cin >> candies;
            total_candies += candies;
        }

        if (total_candies % packets != 0)
        {
            cout << "-1\n";
            continue;
        }

        int moves           {0};
        int average_candies {total_candies / packets};

        for (const auto& candies : candies_per_packet)
        {
            if (candies > average_candies)
            {
                moves += candies - average_candies;
            }
        }

        cout << moves << '\n';
    }

    return 0;
}
