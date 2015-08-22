#include <string>

using namespace std;

class LuckyXor
{
public:
    int construct(int number)
    {
        for (int i {number + 1}; i <= 100; ++i)
        {
            if (is_lucky(number ^ i))
            {
                return i;
            }
        }

        return -1;
    }

    bool is_lucky(int number)
    {
        return to_string(number).find_first_not_of("47") == string::npos;
    }
};
