#include <algorithm>
#include <iostream>
#include <set>

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

    unsigned int records;
    cin >> records;

    set<unsigned int> inside;
    unsigned int min_capacity {0};

    for (unsigned int i {0}; i < records; ++i)
    {
        char type;
        unsigned int number;

        cin >> type >> number;

        if (type == '+')
        {
            inside.insert(number);
            min_capacity = max(min_capacity, inside.size());
        }
        else if (inside.count(number))
        {
            inside.erase(number);
        }
        else
        {
            ++min_capacity;
        }
    }

    cout << min_capacity << '\n';

    return 0;
}
