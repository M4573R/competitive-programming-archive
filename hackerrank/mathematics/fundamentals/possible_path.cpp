#include <iostream>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
T gcd(T left, T right)
{
    while (right)
    {
        left %= right;
        swap(left, right);
    }

    return left;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned long long start_x;
        unsigned long long start_y;

        cin >> start_x >> start_y;

        unsigned long long end_x;
        unsigned long long end_y;

        cin >> end_x >> end_y;

        if (gcd(start_x, start_y) == gcd(end_x, end_y))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
