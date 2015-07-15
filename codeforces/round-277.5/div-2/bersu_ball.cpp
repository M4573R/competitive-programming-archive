#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(vector<int>& boys, vector<int>& girls)
{
    unsigned int boys_count;
    cin >> boys_count;

    boys.resize(boys_count);

    for (auto& boy : boys)
    {
        cin >> boy;
    }

    unsigned int girls_count;
    cin >> girls_count;

    girls.resize(girls_count);

    for (auto& girl : girls)
    {
        cin >> girl;
    }
}

unsigned int max_pairs(const vector<int>& boys, const vector<int>& girls)
{
    unsigned int pairs {0};

    for (unsigned int i {0}, j {0}; i < boys.size() && j < girls.size(); )
    {
        if (abs(boys[i] - girls[j]) <= 1)
        {
            ++pairs;
            ++i;
            ++j;
        }
        else if (boys[i] < girls[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }

    return pairs;
}

int main()
{
    use_io_optimizations();

    vector<int> boys;
    vector<int> girls;

    read_input(boys, girls);

    sort(boys .begin(), boys .end());
    sort(girls.begin(), girls.end());

    cout << max_pairs(boys, girls) << '\n';

    return 0;
}
