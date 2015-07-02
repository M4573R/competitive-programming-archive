#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int stones_count;
    cin >> stones_count;

    string stones_colors;
    cin >> stones_colors;

    if (stones_colors.size() < 2)
    {
        cout << 0;
        return 0;
    }

    unsigned int min_stones_taken {0};

    for (auto i = stones_colors.cbegin(); i != stones_colors.cend() - 1; ++i)
    {
        if (*i == *(i + 1))
        {
            ++min_stones_taken;
        }
    }

    cout << min_stones_taken;

    return 0;
}
