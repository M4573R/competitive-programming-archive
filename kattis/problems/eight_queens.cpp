#include <iostream>
#include <vector>

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

    unsigned int queens {0};

    vector<bool> rows(8);
    vector<bool> columns(8);
    vector<bool> left(15);
    vector<bool> right(15);

    for (unsigned int i {0}; i < 8; ++i)
    {
        for (unsigned int j {0}; j < 8; ++j)
        {
            char piece;
            cin >> piece;

            if (piece == '*')
            {
                ++queens;

                if (rows[i] || columns[j] || left[i + j] || right[i - j + 7])
                {
                    cout << "invalid\n";
                    return 0;
                }

                rows[i] = columns[j] = left[i + j] = right[i - j + 7] = true;
            }
        }
    }

    cout << (queens == 8 ? "valid" : "invalid") << '\n';

    return 0;
}
