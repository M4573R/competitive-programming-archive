#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<bool> erathostenes_sieve(unsigned int up_to)
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

    vector<bool> is_prime {erathostenes_sieve(1 << 16)};

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int number;
        cin >> number;

        cout << is_prime[number] << '\n';
    }

    return 0;
}
