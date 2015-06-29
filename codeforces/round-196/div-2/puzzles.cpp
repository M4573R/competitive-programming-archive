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

    unsigned int children;
    unsigned int puzzles;

    cin >> children >> puzzles;

    vector<unsigned int> pieces(puzzles);

    for (auto& count : pieces)
    {
        cin >> count;
    }

    sort(pieces.begin(), pieces.end());

    unsigned int min_difference {pieces.back()};

    for (unsigned int i {0}; i <= puzzles - children; ++i)
    {
        min_difference = min(min_difference,
                             pieces[i + children - 1] - pieces[i]);
    }

    cout << min_difference << '\n';

    return 0;
}
