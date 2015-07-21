#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int lucky_digits(const string& number)
{
    return count_if(number.cbegin(),
                    number.cend(),
                    [](char digit) { return digit == '4' || digit == '7'; });
}

int main()
{
    use_io_optimizations();

    unsigned int numbers;
    unsigned int upper_limit;

    cin >> numbers >> upper_limit;

    unsigned int count {0};

    for (unsigned int i {0}; i < numbers; ++i)
    {
        string number;
        cin >> number;

        if (lucky_digits(number) <= upper_limit)
        {
            ++count;
        }
    }

    cout << count << '\n';

    return 0;
}
