#include <iostream>
#include <numeric>
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

    for (unsigned int set {1}, stacks; cin >> stacks && stacks != 0; ++set)
    {
        vector<unsigned int> heights(stacks);

        for (auto& height : heights)
        {
            cin >> height;
        }

        auto sum     = accumulate(heights.cbegin(), heights.cend(), 0u);
        auto average = sum / stacks;

        unsigned int moves {0};

        for (auto height : heights)
        {
            if (height > average)
            {
                moves += height - average;
            }
        }

        cout << "Set #"                           << set  << '\n'
             << "The minimum number of moves is " << moves << ".\n\n";
    }

    return 0;
}
