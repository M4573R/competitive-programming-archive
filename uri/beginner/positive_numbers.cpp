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

    unsigned int positive_numbers {0};

    for (unsigned int i {0}; i < 6; ++i)
    {
        double number;
        cin >> number;

        if (number > 0)
        {
            ++positive_numbers;
        }
    }

    cout << positive_numbers << " valores positivos\n";

    return 0;
}
