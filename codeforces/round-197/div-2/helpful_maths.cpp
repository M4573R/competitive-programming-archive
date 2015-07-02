#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<char> summands;

    for (char summand, operation; cin >> summand; cin >> operation)
    {
        summands.push_back(summand);
    }

    sort(summands.begin(), summands.end());

    for (auto summand = summands.begin(); summand != summands.end(); ++summand)
    {
        if (summand != summands.begin())
        {
            cout << '+';
        }

        cout << *summand;
    }

    cout << '\n';

    return 0;
}
