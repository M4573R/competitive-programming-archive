#include <vector>

using namespace std;

class Similars
{
public:
    int maxsim(int L, int R)
    {
        vector<int> count {masks_count(L, R)};

        int max_similarity {0};

        for (int i {0}; i < count.size(); ++i)
        {
            for (int j {i}; j < count.size(); ++j)
            {
                if (i == j && count[i] <= 1)
                {
                    continue;
                }

                if (count[i] == 0 || count[j] == 0)
                {
                    continue;
                }

                max_similarity = max(max_similarity, __builtin_popcount(i & j));
            }
        }

        return max_similarity;
    }

private:
    vector<int> masks_count(int L, int R)
    {
        vector<int> count(1 << 10);

        for (int i {L}; i <= R; ++i)
        {
            int mask {0};

            for (int j {i}; j > 0; j /= 10)
            {
                mask |= (1 << (j % 10));
            }

            ++count[mask];
        }

        return count;
    }
};
