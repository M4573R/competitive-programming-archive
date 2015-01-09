#include <iostream>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int years;
    unsigned int current_number;

    cin >> years >> current_number;

    unsigned int expected_sum {current_number};
    unsigned int actual_sum   {0};

    for (unsigned int i {0}; i < years; ++i)
    {
        unsigned int displayed;
        unsigned int entered;

        cin >> displayed >> entered;

        expected_sum += displayed;
        actual_sum   += entered;
    }

    if (expected_sum >= actual_sum + (years + 1) * 2)
    {
        cout << expected_sum - actual_sum - (years + 1) * 2;
    }
    else
    {
        cout << "Big Bang!";
    }

    cout << '\n';

    return 0;
}
