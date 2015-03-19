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

    vector<bool> is_remainder(42);

    for (unsigned int i {0}; i < 10; ++i)
    {
        unsigned int number;
        cin >> number;

        is_remainder[number % 42] = true;
    }

    cout << count(is_remainder.cbegin(), is_remainder.cend(), true) << '\n';

    return 0;
}
