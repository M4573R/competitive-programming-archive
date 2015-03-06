#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int hundreth_prime {541};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool> eratosthenes_sieve(unsigned int up_to)
{
    vector<bool> sieve(up_to + 1, true);

    sieve[0] = false;

    if (up_to > 0)
    {
        sieve[1] = false;
    }

    for (unsigned int i {2}; i * i <= up_to; ++i)
    {
        if (sieve[i])
        {
            for (unsigned int j {i * i}; j <= up_to; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

int main()
{
    use_io_optimizations();

    unsigned int primes;
    cin >> primes;

    vector<bool> is_prime {eratosthenes_sieve(hundreth_prime)};

    for (unsigned int number {2}, found {0}; found < primes; ++number)
    {
        if (is_prime[number])
        {
            ++found;
            cout << number << '\n';
        }
    }

    return 0;
}
