#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline unsigned int& min_height(vector<unsigned int>& towers_heights)
{
    return *min_element(towers_heights.begin(), towers_heights.end());
}

inline unsigned int& max_height(vector<unsigned int>& towers_heights)
{
    return *max_element(towers_heights.begin(), towers_heights.end());
}

inline unsigned int shortest_tower(const vector<unsigned int>& towers_heights)
{
    return (min_element(towers_heights.cbegin(), towers_heights.cend()) -
            towers_heights.cbegin() + 1);
}

inline unsigned int tallest_tower(const vector<unsigned int>& towers_heights)
{
    return (max_element(towers_heights.cbegin(), towers_heights.cend()) -
            towers_heights.cbegin() + 1);
}

int main()
{
    use_io_optimizations();

    unsigned int towers_count;
    unsigned int max_operations;

    cin >> towers_count >> max_operations;

    vector<unsigned int> towers_heights(towers_count);

    for (unsigned int i {0}; i < towers_count; ++i)
    {
        cin >> towers_heights[i];
    }

    unsigned int operations_count {0};
    vector<pair<unsigned int, unsigned int>> operations;

    for (; operations_count < max_operations; ++operations_count)
    {
        if (max_height(towers_heights) - min_height(towers_heights) < 2)
        {
            break;
        }

        operations.push_back(make_pair(tallest_tower(towers_heights),
                                       shortest_tower(towers_heights)));

        min_height(towers_heights) += 1;
        max_height(towers_heights) -= 1;
    }

    cout << max_height(towers_heights) - min_height(towers_heights) << ' '
         << operations_count                                        << '\n';

    for (const auto& operation : operations)
    {
        cout << operation.first << ' ' << operation.second << '\n';
    }

    return 0;
}
