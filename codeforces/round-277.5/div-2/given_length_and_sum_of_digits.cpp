#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string maximum(int length, int sum)
{
    string number(length, '0');

    for (auto& digit : number)
    {
        int value {min(9, sum)};

        sum   -= value;
        digit += value;
    }

    return number;
}

string minimum(int length, int sum)
{
    int first {max(1, sum - (length - 1) * 9)};

    string minimum {maximum(length - 1, sum - first)};

    minimum += '0' + first;
    reverse(minimum.begin(), minimum.end());

    return minimum;
}

int main()
{
    use_io_optimizations();

    int length;
    int sum;

    cin >> length >> sum;

    if (sum == 0)
    {
        if (length == 1)
        {
            cout << "0 0\n";
        }
        else
        {
            cout << "-1 -1\n";
        }
    }
    else if (length * 9 < sum)
    {
        cout << "-1 -1\n";
    }
    else
    {
        cout << minimum(length, sum) << ' ' << maximum(length, sum) << '\n';
    }

    return 0;
}
