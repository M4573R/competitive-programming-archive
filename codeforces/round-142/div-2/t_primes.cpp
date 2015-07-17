#include <iostream>
#include <set>
#include <vector>

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

    vector<bool> is_prime(1000000 + 1, true);

    for (unsigned int i {2}; i * i < is_prime.size(); ++i)
    {
        if (is_prime[i])
        {
            for (unsigned int j {i * i}; j < is_prime.size(); j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    set<unsigned long long> prime_squares;

    for (unsigned int i {2}; i < is_prime.size(); ++i)
    {
        if (is_prime[i])
        {
            prime_squares.insert(static_cast<unsigned long long>(i) * i);
        }
    }

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned long long number;
        cin >> number;

        cout << (prime_squares.count(number) ? "YES" : "NO") << '\n';
    }

    return 0;
}
