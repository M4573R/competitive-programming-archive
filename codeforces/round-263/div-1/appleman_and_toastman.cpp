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

    unsigned int size;
    cin >> size;

    vector<unsigned int> group(size);

    for (auto& number : group)
    {
        cin >> number;
    }

    sort(group.begin(), group.end());

    unsigned long long max_score {0};

    for (unsigned int i {0}; i < size; ++i)
    {
        max_score += static_cast<unsigned long long>(group[i]) * min(i + 2, size);
    }

    cout << max_score << '\n';

    return 0;
}
