#include <iostream>
#include <map>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline unsigned int holes_in_uppercase_character(char uppercase_character)
{
    static map<char, unsigned int> holes {
        {'A', 1}, {'B', 2}, {'C', 0}, {'D', 1}, {'E', 0}, {'F', 0}, {'G', 0},
        {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0},
        {'O', 1}, {'P', 1}, {'Q', 1}, {'R', 1}, {'S', 0}, {'T', 0}, {'U', 0},
        {'V', 0}, {'W', 0}, {'X', 0}, {'Y', 0}, {'Z', 0}
    };

    return holes[uppercase_character];
}

unsigned int holes_in_uppercase_string(string& uppercase_string)
{
    unsigned int holes {0};

    for (char character : uppercase_string)
    {
        holes += holes_in_uppercase_character(character);
    }

    return holes;
}

int main()
{
    use_io_optimizations();

    unsigned int number_of_test_cases;
    cin >> number_of_test_cases;

    for (unsigned int i {0}; i < number_of_test_cases; ++i)
    {
        string test_case;
        cin >> test_case;

        cout << holes_in_uppercase_string(test_case) << '\n';
    }

    return 0;
}
