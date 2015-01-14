#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename T>
T partition(vector<T>& array, unsigned int left, unsigned int right)
{
    unsigned int pivot_index = left + rand() % (right - left + 1);
    T pivot                  = array[pivot_index];

    swap(array[pivot_index], array[left]);

    unsigned int i = left;
    unsigned int j = right + 1;

    while (i < j)
    {
        while (array[++i] < pivot && i < right)
        { }

        while (array[--j] > pivot && j > left)
        { }

        if (i < j)
        {
            swap(array[i], array[j]);
        }
    }

    swap(array[left], array[j]);

    return j;
}

template <typename T>
T select(vector<T>& array,
         unsigned int index,
         unsigned int left,
         unsigned int right)
{
    if (left >= right)
    {
        return array[left];
    }

    int pivot_index = partition(array, left, right);

    if (pivot_index == index)
    {
        return array[pivot_index];
    }
    else if (pivot_index < index)
    {
        return select(array, index, pivot_index + 1, right);
    }
    else
    {
        return select(array, index, left, pivot_index - 1);
    }
}

template <typename T>
T select(vector<T>& array, unsigned int index)
{
    return select(array, index, 0, array.size() - 1);
}

int main()
{
    use_io_optimizations();

    srand(time(NULL));

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int shoes;
        unsigned int index;

        cin >> shoes >> index;

        vector<unsigned int> shoes_rating(shoes);

        for (unsigned int j = 0; j < shoes; ++j)
        {
            cin >> shoes_rating[j];
        }

        cout << select(shoes_rating, shoes - index) << '\n';
    }

    return 0;
}
