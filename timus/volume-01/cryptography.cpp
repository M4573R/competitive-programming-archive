#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool> erathostenes_sieve(unsigned int upper_limit)
{
    vector<bool> is_prime(upper_limit + 1, true);

    is_prime[0] = false;

    if (upper_limit > 0)
    {
        is_prime[1] = false;
    }

    for (unsigned int i {2}; i * i <= upper_limit; ++i)
    {
        if (is_prime[i])
        {
            for (unsigned int j {i * i}; j <= upper_limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

vector<unsigned int> primes_up_to(unsigned int upper_limit)
{
    auto is_prime = erathostenes_sieve(upper_limit);

    vector<unsigned int> primes;

    for (unsigned int i {0}; i <= upper_limit; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

int main()
{
    use_io_optimizations();

    auto primes = primes_up_to(163841);

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int position;
        cin >> position;

        cout << primes[position - 1] << '\n';
    }


    return 0;
}
