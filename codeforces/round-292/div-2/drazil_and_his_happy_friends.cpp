#include <algorithm>
#include <bits/stdc++.h>
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

    unsigned int boys;
    unsigned int girls;

    cin >> boys >> girls;

    unsigned int gcd {__gcd(boys, girls)};
    vector<bool> happy(gcd);

    unsigned int happy_boys;
    cin >> happy_boys;

    for (unsigned int i {0}; i < happy_boys; ++i)
    {
        unsigned int boy;
        cin >> boy;

        happy[boy % gcd] = true;
    }

    unsigned int happy_girls;
    cin >> happy_girls;

    for (unsigned int i {0}; i < happy_girls; ++i)
    {
        unsigned int girl;
        cin >> girl;

        happy[girl % gcd] = true;
    }

    for (auto is_happy : happy)
    {
        if (!is_happy)
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
