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

    unsigned int friends;
    unsigned int rounds;

    cin >> friends >> rounds;

    vector<bool> invited(friends + 1, true);

    for (unsigned int i {0}; i < rounds; ++i)
    {
        unsigned int number;
        cin >> number;

        for (unsigned int position {0}, j {1}; j <= friends; ++j)
        {
            if (invited[j])
            {
                ++position;
            }

            if (position % number == 0)
            {
                invited[j] = false;
            }
        }
    }

    for (unsigned int i {1}; i <= friends; ++i)
    {
        if (invited[i])
        {
            cout << i << '\n';
        }
    }

    return 0;
}
