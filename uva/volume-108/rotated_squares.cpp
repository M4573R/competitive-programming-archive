#include <iostream>
#include <string>
#include <vector>

using namespace std;

using SquareSize = vector<string>::size_type;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int occurences(const vector<string>& haystack,
                        const vector<string>& needle)
{
    unsigned int count {0};

    for (SquareSize i {0}; i <= haystack.size() - needle.size(); ++i)
    {
        for (SquareSize j {0}; j <= haystack.size() - needle.size(); ++j)
        {
            bool found {true};

            for (SquareSize x {0}; x < needle.size() && found; ++x)
            {
                for (SquareSize y {0}; y < needle.size() && found; ++y)
                {
                    if (haystack[i + x][j + y] != needle[x][y])
                    {
                        found = false;
                    }
                }
            }

            count += found;
        }
    }

    return count;
}

vector<string> rotate(const vector<string>& square)
{
    vector<string> rotated(square);

    for (SquareSize i {0}; i < square.size(); ++i)
    {
        for (SquareSize j {0}; j < square.size(); ++j)
        {
            rotated[j][square.size() - 1 - i] = square[i][j];
        }
    }

    return rotated;
}

int main()
{
    use_io_optimizations();

    unsigned int size_a;
    unsigned int size_b;

    while (cin >> size_a >> size_b && !(size_a == 0 && size_b == 0))
    {
        vector<string> square_a(size_a);

        for (auto& row : square_a)
        {
            cin >> row;
        }

        vector<string> square_b(size_b);

        for (auto& row : square_b)
        {
            cin >> row;
        }

        cout << occurences(square_a, square_b)                         << ' '
             << occurences(square_a, rotate(square_b))                 << ' '
             << occurences(square_a, rotate(rotate(square_b)))         << ' '
             << occurences(square_a, rotate(rotate(rotate(square_b)))) << '\n';
    }

    return 0;
}
