#include <iostream>
#include <string>

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

    string number;
    cin >> number;

    unsigned int index {1};

    for (auto digit : number)
    {
        index = 2 * index + (digit == '7');
    }

    cout << index - 1 << '\n';

    return 0;
}
