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

    string gift;
    cin >> gift;

    unsigned int days;
    cin >> days;

    vector<bool> swapped(gift.size() / 2);

    for (unsigned int i {0}; i < days; ++i)
    {
        unsigned int position;
        cin >> position;

        swapped[position - 1] = !swapped[position - 1];
    }

    bool should_swap {false};

    for (unsigned int i {0}; i < swapped.size(); ++i)
    {
        should_swap ^= swapped[i];

        if (should_swap)
        {
            swap(gift[i], gift[gift.size() - 1 - i]);
        }
    }

    cout << gift << '\n';

    return 0;
}
