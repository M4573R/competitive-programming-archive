#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int segments;
    unsigned int test_cases;

    cin >> segments >> test_cases;

    vector<unsigned int> widths(segments);

    for (auto& width : widths)
    {
        cin >> width;
    }

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int from;
        unsigned int to;

        cin >> from >> to;

        cout << *min_element(widths.cbegin() + from,
                             widths.cbegin() + to + 1)
             << '\n';
    }

    return 0;
}
