#include <algorithm>
#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int first;
        unsigned int second;
        unsigned int third;

        cin >> first >> second >> third;

        if (first > second)
        {
            swap(first, second);
        }

        if (first > third)
        {
            swap(first, third);
        }

        if (second > third)
        {
            swap(second, third);
        }

        cout << "Case " << i + 1 << ": " << second << '\n';
    }

    return 0;
}
