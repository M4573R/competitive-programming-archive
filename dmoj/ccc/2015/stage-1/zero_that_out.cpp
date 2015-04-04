#include <iostream>
#include <numeric>
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

    unsigned int numbers;
    cin >> numbers;

    vector<unsigned int> correct_numbers;

    for (unsigned int i {0}; i < numbers; ++i)
    {
        unsigned int number;
        cin >> number;

        if (number == 0)
        {
            correct_numbers.pop_back();
        }
        else
        {
            correct_numbers.push_back(number);
        }
    }

    cout << accumulate(correct_numbers.cbegin(), correct_numbers.cend(), 0)
         << '\n';

    return 0;
}
