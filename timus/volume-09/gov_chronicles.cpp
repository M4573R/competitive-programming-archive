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

    vector<unsigned int> contests {
        5, 20, 12, 2, 1, 4, 6, 1, 4, 4, 1, 0
    };

    unsigned int player;
    cin >> player;

    cout << contests[player] << '\n';

    return 0;
}
