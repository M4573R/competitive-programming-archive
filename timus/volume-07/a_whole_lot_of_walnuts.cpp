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

int main()
{
    use_io_optimizations();

    unsigned int experiments;
    cin >> experiments;

    unsigned int lower_bound {2};
    unsigned int upper_bound {10};

    for (unsigned int i {0}; i < experiments; ++i)
    {
        unsigned int walnuts;
        cin >> walnuts;

        string outcome;
        cin >> outcome;

        if (outcome == "hungry")
        {
            lower_bound = max(lower_bound, walnuts);
        }
        else
        {
            upper_bound = min(upper_bound, walnuts);
        }
    }

    if (lower_bound < upper_bound)
    {
        cout << upper_bound;
    }
    else
    {
        cout << "Inconsistent";
    }

    cout << '\n';

    return 0;
}
