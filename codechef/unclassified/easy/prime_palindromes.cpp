#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

constexpr int upper_limit {1003001};

inline void use_io_ioptimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_palindrome(unsigned int n)
{
    unsigned int reversed {0};

    for (unsigned int i {n}; i > 0; i /= 10)
    {
        reversed = reversed * 10 + i % 10;
    }

    return n == reversed;
}

vector<bool> erathostenes_sieve(unsigned int up_to)
{
    vector<bool> sieve(up_to + 1, true);
    sieve[0] = false;

    if (up_to > 0)
    {
        sieve[1] = false;
    }

    unsigned int divisors_bound = sqrt(up_to);

    for (vector<bool>::size_type i {2}; i < divisors_bound; ++i)
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

int main()
{
    use_io_ioptimizations();

    unsigned int lower_limit;
    cin >> lower_limit;

    vector<bool> sieve = erathostenes_sieve(upper_limit);

    for (vector<bool>::size_type i {lower_limit}; i < sieve.size(); ++i)
    {
        if (sieve[i] && is_palindrome(i))
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
