#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int merge(vector<unsigned int>& array,
                   vector<unsigned int>::size_type left,
                   vector<unsigned int>::size_type middle,
                   vector<unsigned int>::size_type right)
{
    unsigned int inversions {0};

    vector<unsigned int> merged(right - left + 1);

    vector<unsigned int>::size_type low_iter    {left};
    vector<unsigned int>::size_type high_iter   {middle + 1};
    vector<unsigned int>::size_type merged_iter {0};

    while (low_iter <= middle && high_iter <= right)
    {
        if (array[low_iter] <= array[high_iter])
        {
            merged[merged_iter++] = array[low_iter++];
        }
        else
        {
            merged[merged_iter++] = array[high_iter++];
            inversions           += (middle - low_iter + 1);
        }
    }

    while (low_iter <= middle)
    {
        merged[merged_iter++] = array[low_iter++];
    }

    while (high_iter <= right)
    {
        merged[merged_iter++] = array[high_iter++];
    }

    for (auto i {left}; i <= right; ++i)
    {
        array[i] = merged[i - left];
    }

    return inversions;
}

unsigned int count_inversions(vector<unsigned int>& array,
                              vector<unsigned int>::size_type left,
                              vector<unsigned int>::size_type right)
{
    if (left >= right)
    {
        return 0;
    }

    auto middle = (left + right) / 2;

    unsigned int inversions = 0;

    inversions += count_inversions(array, left, middle);
    inversions += count_inversions(array, middle + 1, right);
    inversions += merge(array, left, middle, right);

    return inversions;
}

unsigned int count_inversions(vector<unsigned int>& array)
{
    return count_inversions(array, 0, array.size() - 1);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int players;
        cin >> players;

        vector<unsigned int> distribution(players);

        for (unsigned int j {0}; j < players; ++j)
        {
            cin >> distribution[j];
        }

        cout << 2 * count_inversions(distribution) << '\n';
    }

    return 0;
}
