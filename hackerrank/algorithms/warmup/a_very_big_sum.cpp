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

    unsigned int numbers;
    cin >> numbers;

    unsigned long long sum {0};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned long long number;
        cin >> number;

        sum += number;
    }

    cout << sum << '\n';

    return 0;
}
