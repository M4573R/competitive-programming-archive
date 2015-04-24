#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    freopen("sortmach.in",  "r", stdin);
    freopen("sortmach.out", "w", stdout);

    int boxes;
    cin >> boxes;

    vector<int> balls(boxes);

    for (int i = 0; i < boxes; ++i)
    {
        cin >> balls[i];
    }

    int min_moves = numeric_limits<int>::max();

    for (int i = 0; i < boxes; ++i)
    {
        int moves = 0;

        for (int j = 0; j < boxes; ++j)
        {
            moves += balls[j] * min(abs(i - j), boxes - abs(i - j));
        }

        min_moves = min(min_moves, moves);
    }

    cout << min_moves << '\n';

    return 0;
}
