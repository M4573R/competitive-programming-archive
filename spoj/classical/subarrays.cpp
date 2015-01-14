#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class StaticRmq
{
public:
    StaticRmq(const vector<unsigned int>& array):
        ranges(array.size(), vector<unsigned int>(log2(array.size()) + 1))
    {
        typedef vector<unsigned int>::size_type index;

        index n = array.size();

        for (index i = 0; i < n; ++i)
        {
            ranges[i][0] = array[i];
        }

        for (index j = 1; (1 << j) <= n; ++j)
        {
            for (index i = 0; i + (1 << j) - 1 < n; ++i)
            {
                ranges[i][j] = max(ranges[i][j - 1],
                                   ranges[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    unsigned int get(unsigned int left, unsigned int right) const
    {
        unsigned int k = log2(right - left + 1);

        return max(ranges[left][k], ranges[right - (1 << k) + 1][k]);
    }

private:
    vector< vector<unsigned int> > ranges;
};

void read_input(unsigned int& elements_count,
                vector<unsigned int>& elements,
                unsigned int& subarray_size)
{
    cin >> elements_count;
    elements = vector<unsigned int>(elements_count);

    for (unsigned int i = 0; i < elements_count; ++i)
    {
        cin >> elements[i];
    }

    cin >> subarray_size;
}

void write_output(unsigned int elements_count,
                  unsigned int subarray_size,
                  const StaticRmq& rmq)
{
    for (unsigned int i = 0; i < elements_count - subarray_size + 1; ++i)
    {
        cout << rmq.get(i, i + subarray_size - 1);

        if (i < elements_count - 1)
        {
            cout << ' ';
        }
    }

    cout << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int         elements_count;
    vector<unsigned int> elements;
    unsigned int         subarray_size;

    read_input(elements_count, elements, subarray_size);

    StaticRmq rmq(elements);

    write_output(elements_count, subarray_size, rmq);

    return 0;
}
