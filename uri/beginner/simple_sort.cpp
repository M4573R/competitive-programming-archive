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

    vector<int> numbers(3);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    vector<int> sorted {numbers};
    sort(sorted.begin(), sorted.end());

    for (auto number : sorted)
    {
        cout << number << '\n';
    }

    cout << '\n';

    for (auto number : numbers)
    {
        cout << number << '\n';
    }

    return 0;
}
