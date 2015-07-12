#include <algorithm>
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

    unsigned int length;
    cin >> length;

    vector<unsigned long long> sums(100001);

    for (unsigned int i {0}; i < length; ++i)
    {
        unsigned int number;
        cin >> number;

        sums[number] += number;
    }

    vector<unsigned long long> subtasks(100001);

    subtasks[0] = 0;
    subtasks[1] = sums[1];

    for (unsigned int i {2}; i < subtasks.size(); ++i)
    {
        subtasks[i] = max(subtasks[i - 1], subtasks[i - 2] + sums[i]);
    }

    cout << subtasks.back() << '\n';

    return 0;
}
