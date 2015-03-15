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

    unsigned int lower_bound;
    unsigned int upper_bound;

    cin >> lower_bound >> upper_bound;

    for (unsigned int i {lower_bound}; i <= upper_bound; i += 60)
    {
        cout << "All positions change in year " << i << '\n';
    }

    return 0;
}
