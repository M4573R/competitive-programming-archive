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

    unsigned int flowers;
    cin >> flowers;

    vector<unsigned int> beauties(flowers);

    for (auto& beauty : beauties)
    {
        cin >> beauty;
    }

    auto minimum = *min_element(beauties.cbegin(), beauties.cend());
    auto maximum = *max_element(beauties.cbegin(), beauties.cend());

    auto min_count = count(beauties.cbegin(), beauties.cend(), minimum);
    auto max_count = count(beauties.cbegin(), beauties.cend(), maximum);

    cout << maximum - minimum << ' ';

    if (minimum == maximum)
    {
        cout << static_cast<long long>(flowers) * (flowers - 1) / 2;
    }
    else
    {
        cout << static_cast<long long>(min_count) * max_count;
    }

    cout << '\n';

    return 0;
}
