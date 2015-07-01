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

    vector<int> numbers(20);

    for (auto& number : numbers)
    {
        cin >> number;
    }

    for (unsigned int i {0}; i < 20; ++i)
    {
        cout << "N[" << i << "] = " << numbers[19 - i] << '\n';
    }

    return 0;
}
