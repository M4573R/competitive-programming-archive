#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool> eratosthenes_seive(unsigned int up_to)
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

    unsigned int up_to;
    cin >> up_to;

    vector<bool> is_prime {eratosthenes_seive(up_to)};

    for (unsigned int i {1}; i <= up_to; ++i)
    {
        cout << is_prime[i] << '\n';
    }

    return 0;
}
