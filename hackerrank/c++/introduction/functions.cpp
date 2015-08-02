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

    vector<int> numbers(4);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    cout << *max_element(numbers.cbegin(), numbers.cend()) << '\n';

    return 0;
}
