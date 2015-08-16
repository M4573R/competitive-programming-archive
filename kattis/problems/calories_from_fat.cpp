#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const vector<unsigned int> calories_per_gram {9, 4, 4, 4, 7};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void parse_line(const string& line,
                unsigned int& fat_value,
                char& fat_units,
                double& line_calories)
{
    istringstream in {line};

    unsigned int calories {0};
    unsigned int percent  {100};

    for (unsigned int i {0}; i < 5; ++i)
    {
        unsigned int value;
        char units;

        in >> value >> units;

        if (i == 0)
        {
            fat_value = value;
            fat_units = units;
        }

        if (units == 'g')
        {
            calories += calories_per_gram[i] * value;
        }
        else if (units == 'C')
        {
            calories += value;
        }
        else
        {
            percent -= value;
        }
    }

    line_calories = calories * 100.0 / percent;
}

void process_line(const string& line,
                  double& fat_calories,
                  double& total_calories)
{
    unsigned int fat_value;
    char fat_units;
    double line_calories;

    parse_line(line, fat_value, fat_units, line_calories);

    if (fat_units == 'g')
    {
        fat_calories += calories_per_gram[0] * fat_value;
    }
    else if (fat_units == 'C')
    {
        fat_calories += fat_value;
    }
    else
    {
        fat_calories += line_calories * fat_value / 100;
    }

    total_calories += line_calories;
}

int main()
{
    use_io_optimizations();

    for (string line; getline(cin, line) && line != "-"; )
    {
        double fat_calories   {0};
        double total_calories {0};

        do
        {
            process_line(line, fat_calories, total_calories);

        } while (getline(cin, line) && line != "-");

        cout << round(fat_calories / total_calories * 100) << "%\n";
    }

    return 0;
}
