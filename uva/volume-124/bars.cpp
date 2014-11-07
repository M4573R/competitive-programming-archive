#include <iostream>
#include <vector>

using namespace std;

constexpr int not_computed {-1};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool could_be_made(const vector<unsigned int>& bars,
                   unsigned int index,
                   long long length,
                   vector<vector<int>>& computed)
{
    if (length < 0)
    {
        return false;
    }

    if (length == 0)
    {
        return true;
    }

    if (index == bars.size())
    {
        return false;
    }

    if (computed[index][length] != not_computed)
    {
        return computed[index][length];
    }
    else if (could_be_made(bars, index + 1, length, computed) ||
             could_be_made(bars, index + 1, length - bars[index], computed))
    {
        return true;
    }
    else
    {
        return computed[index][length] = false;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int target_length;
        unsigned int bars_count;

        cin >> target_length >> bars_count;

        vector<unsigned int> bars(bars_count);

        for (unsigned int j {0}; j < bars_count; ++j)
        {
            cin >> bars[j];
        }

        vector<vector<int>> computed(
            bars_count,
            vector<int>(target_length + 1, not_computed)
        );

        if (could_be_made(bars, 0, target_length, computed))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << '\n';
    }

    return 0;
}
