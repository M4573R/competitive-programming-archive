#include <string>

using namespace std;

class SquareScoresDiv2
{
public:
    int getscore(string present)
    {
        int score {0};

        for (auto i = present.cbegin(); i != present.cend(); ++i)
        {
            int length {1};

            for (; i < present.cend() - 1 && *i == *(i + 1); ++i)
            {
                ++length;
            }

            score += length * (length + 1) / 2;
        }

        return score;
    }
};
