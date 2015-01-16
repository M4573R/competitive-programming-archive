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

    unsigned int upper_bound_a;
    unsigned int upper_bound_b;
    unsigned int sum;

    cin >> upper_bound_a >> upper_bound_b >> sum;

    if (upper_bound_a + upper_bound_b < sum)
    {
        cout << "Impossible";
    }
    else
    {
        unsigned int summand_a {min(sum, upper_bound_a)};
        unsigned int summand_b {sum - summand_a};

        cout << summand_a << ' ' << summand_b;
    }

    cout << '\n';

    return 0;
}
