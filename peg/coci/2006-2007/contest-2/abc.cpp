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

    vector<unsigned int> numbers(3);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    sort(numbers.begin(), numbers.end());

    for (unsigned int i {0}; i < 3; ++i)
    {
        char symbol;
        cin >> symbol;

        cout << numbers[symbol - 'A'] << (i < 2 ? ' ' : '\n');
    }

    return 0;
}
