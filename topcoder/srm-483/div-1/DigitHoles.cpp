#include <map>

using namespace std;

class DigitHoles
{
public:
    static map<int, int> holes_in_digits;

    int numHoles(int number)
    {
        int holes {0};

        while (number > 0)
        {
            holes  += holes_in_digits[number % 10];
            number /= 10;
        }

        return holes;
    }
};

map<int, int> DigitHoles::holes_in_digits = {{0, 1},
                                             {4, 1},
                                             {6, 1},
                                             {8, 2},
                                             {9, 1}};
