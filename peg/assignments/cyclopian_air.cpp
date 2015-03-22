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

    unsigned int cards;
    cin >> cards;

    vector<unsigned int> numbers(cards);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    unsigned int max_product {0};

    for (unsigned int i {0}; i < cards; ++i)
    {
        max_product = max(max_product, numbers[i] * numbers[(i + 1) % cards]);
    }

    cout << max_product << '\n';

    return 0;
}
