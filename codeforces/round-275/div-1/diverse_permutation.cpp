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

    unsigned int length;
    unsigned int distinct;

    cin >> length >> distinct;

    unsigned int low  {1};
    unsigned int high {distinct + 1};

    for (unsigned int i {0}; i < distinct + 1; ++i)
    {
        if (i % 2 == 0)
        {
            cout << low++;
        }
        else
        {
            cout << high--;
        }

        cout << ' ';
    }

    for (unsigned int i {distinct + 1}; i < length; ++i)
    {
        cout << i + 1 << " \n"[i + 1 == length];
    }

    return 0;
}
