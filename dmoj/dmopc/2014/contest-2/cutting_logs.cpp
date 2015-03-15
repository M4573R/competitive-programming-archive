#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char defective     {'X'};
constexpr char non_defective {'O'};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int log_length;
    cin >> log_length;

    string log;
    cin >> log;
    log += defective;

    unsigned int         length  {0};
    vector<unsigned int> lengths;

    for (auto part : log)
    {
        if (part == non_defective)
        {
            ++length;
        }
        else if (length != 0)
        {
            lengths.push_back(length);
            length = 0;
        }
    }

    cout << lengths.size() << '\n';

    for (auto length : lengths)
    {
        cout << string(length, non_defective) << '\n';
    }

    return 0;
}
