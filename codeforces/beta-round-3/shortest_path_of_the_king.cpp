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

    string current;
    string target;

    cin >> current >> target;

    vector<string> moves;

    while (current != target)
    {
        string move;

        if (current[0] < target[0])
        {
            ++current[0];
            move += 'R';
        }
        else if (current[0] > target[0])
        {
            --current[0];
            move += 'L';
        }

        if (current[1] < target[1])
        {
            ++current[1];
            move += 'U';
        }
        else if (current[1] > target[1])
        {
            --current[1];
            move += 'D';
        }

        moves.push_back(move);
    }

    cout << moves.size() << '\n';

    for (const auto& move : moves)
    {
        cout << move << '\n';
    }

    return 0;
}
