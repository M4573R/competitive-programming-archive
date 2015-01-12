#include <iomanip>
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

    cout << fixed << setprecision(6);

    unsigned int places;
    cin >> places;

    double offsets_sum {0};

    for (unsigned int i {0}; i < places; ++i)
    {
        unsigned int offset;
        cin >> offset;

        offsets_sum += offset;
    }

    cout << offsets_sum / places << '\n';

    return 0;
}
