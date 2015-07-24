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

    unsigned int buckets;
    unsigned int numbers;

    cin >> buckets >> numbers;

    vector<bool> is_full(buckets);

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        if (is_full[number % buckets])
        {
            cout << i + 1 << '\n';
            return 0;
        }

        is_full[number % buckets] = true;
    }

    cout << -1 << '\n';

    return 0;
}
