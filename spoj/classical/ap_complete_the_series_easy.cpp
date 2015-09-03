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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned long long third;
        unsigned long long third_to_last;
        unsigned long long sum;

        cin >> third >> third_to_last >> sum;

        unsigned long long length {
            2 * sum / (third + third_to_last)
        };

        unsigned long long difference {
            (third_to_last - third) / (length - 5)
        };

        unsigned long long first {
            third - 2 * (third_to_last - third) / (length - 5)
        };

        cout << length << '\n';

        for (unsigned long long i {0}; i < length; ++i)
        {
            cout << first + i * difference  << " \n"[i + 1 == length];
        }
    }

    return 0;
}
