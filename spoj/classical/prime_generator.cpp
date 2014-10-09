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
    unsigned int upper_bound = sqrt(up_to);

    for (vector<bool>::size_type i = 2; i < sieve.size(); ++i)
    {
        if (sieve[i])
        {
            for (vector<bool>::size_type j = i * i; j < upper_bound; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

vector<unsigned int> primes_between(unsigned int m, unsigned int n)
{
    vector<bool> segmented_sieve(n - m + 1, true);
    vector<bool> sieve = eratosthenes_sieve(floor(sqrt(n)));

    for (vector<bool>::size_type i = 2; i < sieve.size(); ++i)
    {
        if (sieve[i])
        {
            unsigned int first_in_range = ceil(m / static_cast<double>(i)) * i;

            for (vector<bool>::size_type j = max(i * i, first_in_range) - m;
                 j < segmented_sieve.size();
                 j += i)
            {
                segmented_sieve[j] = false;
            }
        }
    }

    vector<unsigned int> primes;

    for (unsigned int i = (m == 1 ? 1 : 0); i < segmented_sieve.size(); ++i)
    {
        if (segmented_sieve[i])
        {
            primes.push_back(i + m);
        }
    }

    return primes;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i = 0; i < test_cases; ++i)
    {
        unsigned int m;
        unsigned int n;

        cin >> m >> n;

        vector<unsigned int> primes = primes_between(m, n);

        for (vector<unsigned int>::const_iterator prime = primes.begin();
             prime != primes.end();
             ++prime)
        {
            cout << *prime << '\n';
        }

        cout << '\n';
    }

    return 0;
}
