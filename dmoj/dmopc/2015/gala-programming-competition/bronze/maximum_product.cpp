#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(unsigned int& cards,
                vector<int>& positive,
                vector<int>& negative)
{
    cin >> cards;

    for (unsigned int i {0}; i < cards; ++i)
    {
        int number;
        cin >> number;

        if (number > 0)
        {
            positive.push_back(number);
        }
        else if (number < 0)
        {
            negative.push_back(number);
        }
    }

}

int main()
{
    use_io_optimizations();

    unsigned int cards;
    vector<int> positive;
    vector<int> negative;

    read_input(cards, positive, negative);

    if (positive.empty() && negative.empty())
    {
        cout << 0 << '\n';
    }
    else if (positive.empty() && negative.size() == 1)
    {
        cout << (cards == 1 ? negative.front() : 0) << '\n';
    }
    else
    {
        long long product {
            accumulate(positive.cbegin(),
                       positive.cend(),
                       1ll,
                       multiplies<long long>()) *
            accumulate(negative.cbegin(),
                       negative.cend(),
                       1ll,
                       multiplies<long long>())
        };

        if (product < 0)
        {
            product /= *max_element(negative.cbegin(), negative.cend());
        }

        cout << product << '\n';
    }

    return 0;
}
