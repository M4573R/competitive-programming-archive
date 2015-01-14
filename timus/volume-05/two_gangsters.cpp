#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int shot_by_harry;
    unsigned int shot_by_larry;

    cin >> shot_by_harry >> shot_by_larry;

    unsigned int total_cans {shot_by_harry + shot_by_larry - 1};

    cout << total_cans - shot_by_harry << ' '
         << total_cans - shot_by_larry << '\n';

    return 0;
}
