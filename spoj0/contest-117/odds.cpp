#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test_case = 0; test_case < test_cases; ++test_case)
    {
        unsigned int numbers_count;
        unsigned int upper_bound;

        cin >> numbers_count >> upper_bound;

        unsigned int min_odd = upper_bound;

        if (upper_bound % 2 == 0)
        {
            ++min_odd;
        }

        vector<unsigned int> numbers(numbers_count);

        for (unsigned int i = 0; i < numbers_count; ++i)
        {
            cin >> numbers[i];

            if (numbers[i] % 2 != 0)
            {
                min_odd = min(min_odd, numbers[i]);
            }
        }

        unsigned int odds = 0;

        for (unsigned int i = 0; i < numbers_count; ++i)
        {
            if (numbers[i] % 2 != 0 || numbers[i] + min_odd <= upper_bound)
            {
                ++odds;
            }
        }

        cout << odds << '\n';
    }

    return 0;
}
