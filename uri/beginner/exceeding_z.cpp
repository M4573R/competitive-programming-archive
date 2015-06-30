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

    int lower_limit;
    int upper_limit;

    cin >> lower_limit;

    while (cin >> upper_limit && upper_limit <= lower_limit)
    { }

    unsigned int length {0};

    for (int i {lower_limit}, sum {0}; sum <= upper_limit; ++i)
    {
        sum += i;
        ++length;
    }

    cout << length << '\n';

    return 0;
}
