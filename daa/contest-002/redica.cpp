#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int size;
    cin >> size;

    vector<int> sequence(size);

    for (unsigned int i {0}; i < size; ++i)
    {
        cin >> sequence[i];
    }

    unsigned long long count {size};

    for (unsigned int to {0}; to < size - 1; ++to)
    {
        unsigned int from {to};

        for (; to < size - 1 && sequence[to] == sequence[to + 1]; ++to)
        { }

        unsigned long long length {to - from + 1};
        count += length * (length - 1) / 2;
    }

    cout << count << '\n';

    return 0;
}
