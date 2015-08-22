#include <iostream>
#include <map>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const map<char, unsigned int> letter_holes {
    {'A', 1}, {'B', 2}, {'C', 0}, {'D', 1}, {'E', 0}, {'F', 0},
    {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0}, {'L', 0},
    {'M', 0}, {'N', 0}, {'O', 1}, {'P', 1}, {'Q', 1}, {'R', 1},
    {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0},
    {'Y', 0}, {'Z', 0}
};

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string text;
        cin >> text;

        unsigned int holes {0};

        for (auto letter : text)
        {
            holes += letter_holes.at(letter);
        }

        cout << holes << '\n';
    }

    return 0;
}
