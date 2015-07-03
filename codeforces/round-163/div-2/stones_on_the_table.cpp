#include <iostream>
#include <string>

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

    unsigned int stones;
    cin >> stones;

    string colors;
    cin >> colors;

    unsigned int min_stones_taken {0};

    for (auto i = colors.cbegin(); i != colors.cend() - 1; ++i)
    {
        if (*i == *(i + 1))
        {
            ++min_stones_taken;
        }
    }

    cout << min_stones_taken << '\n';

    return 0;
}
