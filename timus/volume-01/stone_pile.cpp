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

    unsigned int stones;
    cin >> stones;

    unsigned int total_weight {0};
    vector<unsigned int> weights(stones);

    for (auto& weight : weights)
    {
        cin >> weight;
        total_weight += weight;
    }

    vector<bool> has_pile(total_weight / 2 + 1);
    has_pile[0] = true;

    for (auto weight : weights)
    {
        for (unsigned int i {has_pile.size() - 1}; i >= weight; --i)
        {
            has_pile[i] = has_pile[i] || has_pile[i - weight];
        }
    }

    for (unsigned int i {has_pile.size() - 1}; i >= 0; --i)
    {
        if (has_pile[i])
        {
            cout << total_weight - 2 * i << '\n';
            break;
        }
    }

    return 0;
}
