#include <algorithm>
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

    unsigned int columns;
    cin >> columns;

    vector<unsigned int> heights(columns);

    for (unsigned int i {0}; i < columns; ++i)
    {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    for (unsigned int i {0}; i < columns; ++i)
    {
        cout << heights[i] << (i + 1 < columns ? ' ' : '\n');
    }

    return 0;
}
