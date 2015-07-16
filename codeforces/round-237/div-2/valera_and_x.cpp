#include <iostream>
#include <set>

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

    unsigned int size;
    cin >> size;

    set<char> diagonals;
    set<char> other;

    for (unsigned int i {0}; i < size; ++i)
    {
        for (unsigned int j {0}; j < size; ++j)
        {
            char letter;
            cin >> letter;

            if (i == j || i + j == size - 1)
            {
                diagonals.insert(letter);
            }
            else
            {
                other.insert(letter);
            }
        }
    }

    if (diagonals.size()    == 1 &&
        other.size()        == 1 &&
        *diagonals.cbegin() != *other.cbegin())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
