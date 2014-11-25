#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename T>
class StaticRmq
{
public:
    StaticRmq(const vector<T>& array):
        ranges(array.size(), vector<T>(log2(array.size()) + 1))
    {
        typename vector<T>::size_type n = array.size();

        for (typename vector<T>::size_type i = 0; i < n; ++i)
        {
            ranges[i][0] = array[i];
        }

        for (typename vector<T>::size_type j = 1; (1 << j) <= n; ++j)
        {
            for (typename vector<T>::size_type i = 0; i + (1 << j) - 1 < n; ++i)
            {
                if (ranges[i][j - 1] > ranges[i + (1 << (j - 1))][j - 1])
                {
                    ranges[i][j] = ranges[i][j - 1];
                }
                else
                {
                    ranges[i][j] = ranges[i + (1 << (j - 1))][j - 1];
                }
            }
        }
    }

    T query(unsigned int left, unsigned int right) const
    {
        unsigned int k = log2(right - left + 1);

        if (ranges[left][k] >= ranges[right - (1 << k) + 1][k])
        {
            return ranges[left][k];
        }
        else
        {
            return ranges[right - (1 << k) + 1][k];
        }
    }

private:
    vector< vector<T> > ranges;
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
                  const StaticRmq<unsigned int>& rmq)
{
    for (unsigned int i = 0; i < elements_count - subarray_size + 1; ++i)
    {
        cout << rmq.query(i, i + subarray_size - 1);

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

    StaticRmq<unsigned int> rmq(elements);

    write_output(elements_count, subarray_size, rmq);

    return 0;
}
