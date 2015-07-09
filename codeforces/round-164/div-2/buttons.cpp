#include <iostream>

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

    unsigned int buttons;
    cin >> buttons;

    unsigned int moves {0};

    for (unsigned int i {1}; i <= buttons; ++i)
    {
        moves += i * (buttons - i) + 1;
    }

    cout << moves << '\n';

    return 0;
}
