#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<bool> eratosthenes_sieve(unsigned int up_to)
{
    vector<bool> sieve(up_to + 1, true);
    sieve[0] = false;

    if (up_to > 0)
    {
        sieve[1] = false;
    }

    unsigned int upper_bound = sqrt(up_to);

    for (vector<bool>::size_type i {2}; i < upper_bound; ++i)
    {
        if (sieve[i])
        {
            for (vector<bool>::size_type j {i * i}; j < sieve.size(); j += i)
            {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

vector<unsigned int> primes_between(unsigned int lower, unsigned int upper)
{
    vector<bool> segmented_sieve(upper - lower + 1, true);
    vector<bool> sieve {eratosthenes_sieve(sqrt(upper))};

    for (vector<bool>::size_type i {2}; i < sieve.size(); ++i)
    {
        if (sieve[i])
        {
            unsigned int first_in_range {(lower + i - 1) / i * i};

            for (vector<bool>::size_type j {max(i * i, first_in_range) - lower};
                 j < segmented_sieve.size();
                 j += i)
            {
                segmented_sieve[j] = false;
            }
        }
    }

    vector<unsigned int> primes;

    for (unsigned int i {lower == 1 ? 1 : 0}; i < segmented_sieve.size(); ++i)
    {
        if (segmented_sieve[i])
        {
            primes.push_back(i + lower);
        }
    }

    return primes;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        unsigned int lower;
        unsigned int upper;

        cin >> lower >> upper;

        vector<unsigned int> primes {primes_between(lower, upper)};

        for (auto prime : primes)
        {
            cout << prime << '\n';
        }

        cout << '\n';
    }

    return 0;
}
