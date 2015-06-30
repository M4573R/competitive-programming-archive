#include <iostream>

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

    unsigned int numbers_per_line;
    unsigned int numbers;

    cin >> numbers_per_line >> numbers;

    for (unsigned int i {1}; i <= numbers; ++i)
    {
        cout << i << (i % numbers_per_line ? ' ' : '\n');
    }

    return 0;
}
