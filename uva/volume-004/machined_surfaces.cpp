#include <algorithm>
#include <iostream>
#include <string>

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

    for (unsigned int rows; cin >> rows && rows != 0; )
    {
        cin.ignore();

        unsigned int total_void {0};
        unsigned int min_void   {25};

        for (unsigned int i {0}; i < rows; ++i)
        {
            string row;
            getline(cin, row);

            unsigned int row_void = count(row.cbegin(), row.cend(), ' ');

            total_void += row_void;
            min_void    = min(min_void, row_void);
        }

        cout << total_void - rows * min_void << '\n';
    }

    return 0;
}
