#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> burger_calories  {461, 431, 420, 0};
const vector<unsigned int> side_calories    {100, 57,  70,  0};
const vector<unsigned int> drink_calories   {130, 160, 118, 0};
const vector<unsigned int> dessert_calories {167, 266, 75,  0};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int burger_choice;
    unsigned int side_choice;
    unsigned int drink_choice;
    unsigned int dessert_choice;

    cin >> burger_choice
        >> side_choice
        >> drink_choice
        >> dessert_choice;

    unsigned int total_calories {burger_calories[burger_choice - 1] +
                                 side_calories[side_choice - 1]     +
                                 drink_calories[drink_choice - 1]   +
                                 dessert_calories[dessert_choice - 1]};

    cout << "Your total Calorie count is " << total_calories << ".\n";

    return 0;
}
