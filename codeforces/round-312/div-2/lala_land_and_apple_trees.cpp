#include <algorithm>
#include <functional>
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

    unsigned int trees;
    cin >> trees;

    vector<pair<int, unsigned int>> negative;
    vector<pair<int, unsigned int>> positive;

    for (unsigned int i {0}; i < trees; ++i)
    {
        int position;
        unsigned int apples;

        cin >> position >> apples;

        if (position < 0)
        {
            negative.emplace_back(position, apples);
        }
        else
        {
            positive.emplace_back(position, apples);
        }
    }

    sort(negative.begin(), negative.end(), greater<pair<int, unsigned int>>());
    sort(positive.begin(), positive.end());

    unsigned int apples {0};

    for (unsigned int i {0}; i < min(negative.size(), positive.size() + 1); ++i)
    {
        apples += negative[i].second;
    }

    for (unsigned int i {0}; i < min(negative.size() + 1, positive.size()); ++i)
    {
        apples += positive[i].second;
    }

    cout << apples << '\n';

    return 0;
}
