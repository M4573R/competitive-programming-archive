#include <iostream>
#include <map>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    map<char, unsigned int> weights {
        {'q', 9}, {'Q', 9},
        {'r', 5}, {'R', 5},
        {'b', 3}, {'B', 3},
        {'n', 3}, {'N', 3},
        {'p', 1}, {'P', 1}
    };

    unsigned int white_weight {0};
    unsigned int black_weight {0};

    for (unsigned int i {0}; i < 8; ++i)
    {
        for (unsigned int j {0}; j < 8; ++j)
        {
            char piece;
            cin >> piece;

            if (isupper(piece))
            {
                white_weight += weights[piece];
            }
            else
            {
                black_weight += weights[piece];
            }
        }
    }

    if (white_weight < black_weight)
    {
        cout << "Black";
    }
    else if (white_weight > black_weight)
    {
        cout << "White";
    }
    else
    {
        cout << "Draw";
    }

    cout << '\n';

    return 0;
}
