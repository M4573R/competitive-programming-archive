#include <iostream>
#include <utility>

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

    int lower;
    int upper;

    cin >> lower >> upper;

    if (lower > upper)
    {
        swap(lower, upper);
    }

    for (int i {lower + 1}; i < upper; ++i)
    {
        if (i % 5 == 2 || i % 5 == 3)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
