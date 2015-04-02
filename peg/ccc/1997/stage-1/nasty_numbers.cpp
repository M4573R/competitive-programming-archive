#include <iostream>
#include <unordered_set>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_nasty(unsigned int number)
{
    unordered_set<unsigned int> sums;
    unordered_set<unsigned int> differences;

    for (unsigned int i {1}; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            unsigned int j {number / i};

            if (sums.count(j - i) || differences.count(i + j))
            {
                return true;
            }

            sums.insert(i + j);
            differences.insert(j - i);
        }
    }

    return false;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int number;
        cin >> number;

        cout << number << " is " << (is_nasty(number) ? "nasty" : "not nasty") << '\n';
    }

    return 0;
}
