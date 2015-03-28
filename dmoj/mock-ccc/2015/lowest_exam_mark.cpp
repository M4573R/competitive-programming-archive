#include <cmath>
#include <iostream>

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

    unsigned int current;
    unsigned int target;
    unsigned int weight;

    cin >> current >> target >> weight;

    double needed_mark {
        ceil((100 * (target - 0.5) - current * (100 - weight)) / weight)
    };

    if (needed_mark > 100)
    {
        cout << "DROP THE COURSE";
    }
    else
    {
        cout << max(0.0, needed_mark);
    }

    cout << '\n';

    return 0;
}
