#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print_even_order(vector<unsigned int>::const_iterator left,
                      vector<unsigned int>::const_iterator right)
{
    if (left > right)
    {
        return;
    }

    auto middle = right;

    while (middle >= left && *middle >= *right)
    {
        --middle;
    }

    print_even_order(middle + 1, right - 1);
    print_even_order(left, middle);

    cout << *right << '\n';
}

int main()
{
    use_io_optimizations();

    unsigned int members;
    cin >> members;

    vector<unsigned int> odd_order(members);

    for (auto& id : odd_order)
    {
        cin >> id;
    }

    print_even_order(odd_order.begin(), odd_order.end() - 1);

    return 0;
}
