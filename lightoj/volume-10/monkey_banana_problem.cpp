#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int size;
        cin >> size;

        vector< vector<unsigned int> > bananas(
            2 * size, vector<unsigned int>(size + 1)
        );

        for (unsigned int i = 1; i <= size; ++i)
        {
            for (unsigned int j = 1; j <= i; ++j)
            {
                cin >> bananas[i][j];

                bananas[i][j] += max(bananas[i - 1][j - 1],
                                     bananas[i - 1][j]);
            }
        }

        for (unsigned int i = 1; i <= size - 1; ++i)
        {
            for (unsigned int j = 1; j <= size - i; ++j)
            {
                cin >> bananas[size + i][j];

                bananas[size + i][j] += max(bananas[size + i - 1][j],
                                            bananas[size + i - 1][j + 1]);
            }
        }

        cout << "Case " << test << ": " << bananas.back()[1] << '\n';
    }

    return 0;
}
