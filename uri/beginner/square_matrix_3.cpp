#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> justifications {
    0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 9
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (unsigned int lines; cin >> lines && lines > 0; )
    {
        for (unsigned int i {0}; i < lines; ++i)
        {
            for (unsigned int j {0}; j < lines; ++j)
            {
                cout << setw(justifications[lines])
                     << (1 << (i + j))
                     << (j + 1 < lines ? ' ' : '\n');
            }
        }

        cout << '\n';
    }

    return 0;
}
