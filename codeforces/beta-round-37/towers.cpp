#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class BySecond
{
public:
    bool operator()(const pair<unsigned int, unsigned int>& left,
                    const pair<unsigned int, unsigned int>& right)
    {
        return left.second < right.second;
    }
};

int main()
{
    use_io_optimizations();

    unsigned int bars;
    cin >> bars;

    map<unsigned int, unsigned int> count;

    for (unsigned int i {0}; i < bars; ++i)
    {
        unsigned int length;
        cin >> length;

        ++count[length];
    }

    cout << max_element(count.cbegin(),
                        count.cend(),
                        BySecond())->second
         << ' '
         << count.size()
         << '\n';


    return 0;
}
