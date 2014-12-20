#include <cctype>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr int alphabet_size {26};

enum class NumerationSystem
{
    First, Second
};

NumerationSystem numeration_system(string& coordinates)
{
    if (isalpha(coordinates[1]) || coordinates.find('C', 1) == string::npos)
    {
        return NumerationSystem::First;
    }
    else
    {
        return NumerationSystem::Second;
    }
}

string first_to_second(string& coordinates)
{
    ostringstream to_second;

    string::size_type i {0};
    unsigned int column {0};

    for (; i < coordinates.size() && isalpha(coordinates[i]); ++i)
    {
        column = column * alphabet_size + coordinates[i] - 'A' + 1;
    }

    to_second << 'R' << coordinates.substr(i);
    to_second << 'C' << column;

    return to_second.str();
}

string second_to_first(string& coordinates)
{
    istringstream from_second {coordinates};
    ostringstream to_first;

    char delimiter;

    unsigned int row;
    unsigned int column;

    from_second >> delimiter >> row;
    from_second >> delimiter >> column;

    list<char> converted_column;

    while (column > 0)
    {
        --column;
        converted_column.push_front('A' + column % alphabet_size);
        column /= alphabet_size;
    }

    for (auto symbol : converted_column)
    {
        to_first << symbol;
    }

    to_first << row;

    return to_first.str();
}

int main()
{
    use_io_optimizations();

    unsigned int number_of_coordinates;
    cin >> number_of_coordinates;

    for (unsigned int i {0}; i < number_of_coordinates; ++i)
    {
        string cell_coordinates;
        cin >> cell_coordinates;

        switch (numeration_system(cell_coordinates))
        {
        case NumerationSystem::First:
            cout << first_to_second(cell_coordinates) << '\n';
            break;

        case NumerationSystem::Second:
            cout << second_to_first(cell_coordinates) << '\n';
            break;
        }
    }

    return 0;
}
