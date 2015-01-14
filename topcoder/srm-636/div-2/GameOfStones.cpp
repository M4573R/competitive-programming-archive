#include <algorithm>
#include <vector>

using namespace std;

class GameOfStones
{
public:
    int count(vector<int> stones)
    {
        int stones_count {0};
        for_each(stones.begin(),
                 stones.end(),
                 [&](int n) { stones_count += n; });

        int piles_count = stones.size();

        if (stones_count % piles_count)
        {
            return -1;
        }

        int stones_average {stones_count / piles_count};
        int moves          {0};

        for (vector<int>::const_iterator stones_in_pile = stones.cbegin();
             stones_in_pile != stones.cend();
             ++stones_in_pile)
        {
            if ((stones_average - *stones_in_pile) % 2)
            {
                return -1;
            }

            if (*stones_in_pile < stones_average)
            {
                moves += (stones_average - *stones_in_pile) / 2;
            }
        }

        return moves;
    }
};
