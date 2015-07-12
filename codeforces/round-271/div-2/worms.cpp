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

    unsigned int piles;
    cin >> piles;

    vector<unsigned int> worms(piles + 1);

    for (unsigned int i {1}; i <= piles; ++i)
    {
        cin >> worms[i];
        worms[i] += worms[i - 1];
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int worm;
        cin >> worm;

        cout << lower_bound(worms.cbegin(), worms.cend(), worm) - worms.cbegin()
             << '\n';
    }

    return 0;
}
