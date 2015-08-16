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

    string preferences;
    cin >> preferences;

    vector<unsigned int> moves(3);
    vector<char> positions(3, preferences.front());

    for (auto i = preferences.cbegin() + 1; i != preferences.cend(); ++i)
    {
        moves[0] += (*i != positions[0]);
        moves[1] += (*i != positions[1]);
        moves[2] += (*i != positions[2]);

        positions.assign(3, *i);

        moves[0] += (positions[0] != 'U');
        moves[1] += (positions[1] != 'D');

        positions[0] = 'U';
        positions[1] = 'D';
    }

    cout << moves[0] << '\n'
         << moves[1] << '\n'
         << moves[2] << '\n';

    return 0;
}
