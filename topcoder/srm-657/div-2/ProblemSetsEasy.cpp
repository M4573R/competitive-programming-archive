#include <algorithm>

using namespace std;

class ProblemSetsEasy
{
public:
    int maxSets(int E, int EM, int M, int MH, int H)
    {
        E += EM;
        H += MH;

        while (M < E && M < H && (EM > 0 || MH > 0))
        {
            if (E > H)
            {
                swap(E, H);
                swap(EM, MH);
            }

            if (MH > 0)
            {
                --H;
                --MH;
                ++M;
            }
            else
            {
                --E;
                --EM;
                ++M;
            }
        }

        return min(E, min(E, H));
    }
};
