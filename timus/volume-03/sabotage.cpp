#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int numbers_count;
    cin >> numbers_count;

    vector<unsigned int> numbers(numbers_count);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    sort(numbers.begin(), numbers.end(), greater<unsigned int>());

    for (auto number : numbers)
    {
        cout << number << '\n';
    }

    return 0;
}
