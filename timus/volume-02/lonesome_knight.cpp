#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<pair<unsigned int, unsigned int>> knight_moves {
    {-2, -1}, {-2, +1},
    {-1, -2}, {-1, +2},
    {+1, -2}, {+1, +2},
    {+2, -1}, {+2, +1}
};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline bool is_valid(char file, int rank)
{
    return file >= 'a' && file <= 'h' && rank >= 1 && rank <= 8;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        char file;
        int rank;

        cin >> file >> rank;

        unsigned int possible_moves {0};

        for (const auto& move : knight_moves)
        {
            if (is_valid(file + move.first, rank + move.second))
            {
                ++possible_moves;
            }
        }

        cout << possible_moves << '\n';
    }

    return 0;
}
