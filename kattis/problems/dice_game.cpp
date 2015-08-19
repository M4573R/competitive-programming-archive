#include <iostream>
#include <numeric>
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

    vector<unsigned int> gunnars(4);
    vector<unsigned int> emmas(4);

    cin >> gunnars[0] >> gunnars[1] >> gunnars[2] >> gunnars[3]
        >> emmas[0]   >> emmas[1]   >> emmas[2]   >> emmas[3];

    auto gunnars_sum = accumulate(gunnars.cbegin(), gunnars.cend(), 0u);
    auto emmas_sum   = accumulate(emmas.cbegin(),   emmas.cend(),   0u);

    if (gunnars_sum > emmas_sum)
    {
        cout << "Gunnar\n";
    }
    else if (gunnars_sum < emmas_sum)
    {
        cout << "Emma\n";
    }
    else
    {
        cout << "Tie\n";
    }

    return 0;
}
