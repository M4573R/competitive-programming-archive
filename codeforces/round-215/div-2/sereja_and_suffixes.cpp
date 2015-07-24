#include <iostream>
#include <set>
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

    unsigned int size;
    unsigned int queries;

    cin >> size >> queries;

    vector<unsigned int> numbers(size);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    set<unsigned int> distinct;
    vector<unsigned int> count(size);

    for (unsigned int i {size}; i >= 1; --i)
    {
        distinct.insert(numbers[i - 1]);
        count[i - 1] = distinct.size();
    }

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int from;
        cin >> from;

        cout << count[from - 1] << '\n';
    }

    return 0;
}
