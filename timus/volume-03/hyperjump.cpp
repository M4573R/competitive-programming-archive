#include <algorithm>
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

    unsigned int elements;
    cin >> elements;

    int sum     {0};
    int max_sum {0};

    for (unsigned int i {0}; i < elements; ++i)
    {
        int element;
        cin >> element;

        sum     = max(0, sum + element);
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << '\n';

    return 0;
}
