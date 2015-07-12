#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int max_gain(const vector<int>& gains)
{
    int sum     {gains[0]};
    int maximum {gains[0]};

    for (unsigned int i {1}; i < gains.size(); ++i)
    {
        sum     = max(gains[i], sum + gains[i]);
        maximum = max(maximum, sum);
    }

    return maximum;
}

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    unsigned int ones {0};
    vector<int> gains(length);

    for (unsigned int i {0}; i < length; ++i)
    {
        unsigned int number;
        cin >> number;

        if (number == 0)
        {
            gains[i] = 1;
        }
        else
        {
            ++ones;
            gains[i] = -1;
        }
    }

    cout << max_gain(gains) + ones << '\n';

    return 0;
}
