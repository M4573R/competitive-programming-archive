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

    unsigned int first;
    unsigned int second;

    cin >> first >> second;

    unsigned int solutions {0};

    for (unsigned int i {0}; i * i <= first; ++i)
    {
        unsigned int j {first - i * i};

        if (i + j * j == second)
        {
            ++solutions;
        }
    }

    cout << solutions << '\n';

    return 0;
}
