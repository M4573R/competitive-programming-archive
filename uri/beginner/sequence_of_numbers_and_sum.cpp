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

    for (int lower, upper; cin >> lower >> upper && lower > 0 && upper > 0; )
    {
        if (lower > upper)
        {
            swap(lower, upper);
        }

        for (int i {lower}; i <= upper; ++i)
        {
            cout << i << ' ';
        }

        cout << "Sum=" << (lower + upper) * (upper - lower + 1) / 2 << '\n';
    }

    return 0;
}
