#include <algorithm>
#include <iostream>

using namespace std;

constexpr unsigned int left_feet  {40};
constexpr unsigned int right_feet {40};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int left_slippers;
    unsigned int right_slippers;

    cin >> left_slippers >> right_slippers;

    cout << max(2 * right_slippers + left_feet,
                (2 * (right_feet - 1) + left_feet +
                 2 * (left_slippers - left_feet) + 1))
         << '\n';

    return 0;
}
