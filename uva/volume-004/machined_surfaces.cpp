#include <algorithm>
#include <iostream>
#include <string>
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

    for (unsigned int rows; cin >> rows && rows != 0; )
    {
        cin.ignore();

        vector<unsigned int> holes(rows);

        for (auto& hole : holes)
        {
            string row;
            getline(cin, row);

            hole = count(row.cbegin(), row.cend(), ' ');
        }

        unsigned int total_void {accumulate(holes.cbegin(), holes.cend(), 0u)};
        unsigned int min_void   {*min_element(holes.cbegin(), holes.cend())};

        cout << total_void - rows * min_void << '\n';
    }

    return 0;
}
