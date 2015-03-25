#include <algorithm>
#include <iomanip>
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

    cout << fixed << setprecision(1);

    unsigned int oelfinns;
    cin >> oelfinns;

    vector<unsigned int> clothing_sizes(oelfinns);

    for (auto& clothing_size : clothing_sizes)
    {
        cin >> clothing_size;
    }

    sort(clothing_sizes.begin(), clothing_sizes.end());

    if (oelfinns % 2 == 0)
    {
        cout << static_cast<double>(clothing_sizes[oelfinns / 2 - 1] +
                                    clothing_sizes[oelfinns / 2]) / 2;
    }
    else
    {
        cout << static_cast<double>(clothing_sizes[oelfinns / 2]);
    }

    cout << '\n';

    return 0;
}
