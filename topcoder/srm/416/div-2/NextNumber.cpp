#include <algorithm>
#include <list>

using namespace std;

class NextNumber
{
public:
    int getNextNumber(int N)
    {
        list<int> bits;

        for (int i {N}; i != 0; i /= 2)
        {
            bits.push_front(i % 2);
        }

        bits.push_front(0);
        next_permutation(bits.begin(), bits.end());

        int next_with_same_weight {0};

        for (auto i = bits.cbegin(); i != bits.cend(); ++i)
        {
            next_with_same_weight *= 2;
            next_with_same_weight += *i;
        }

        return next_with_same_weight;
    }
};
