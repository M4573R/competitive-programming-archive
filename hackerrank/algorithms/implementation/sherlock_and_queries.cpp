#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr unsigned int modulo {1000000007};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int n;
    unsigned int m;

    cin >> n >> m;

    vector<unsigned long long> integers(n);
    vector<unsigned long long> divisors(m);
    vector<unsigned long long> coefficients(m);

    for (auto& integer : integers)
    {
        cin >> integer;
    }

    for (auto& divisor : divisors)
    {
        cin >> divisor;
    }

    for (auto& coefficient : coefficients)
    {
        cin >> coefficient;
    }

    map<unsigned int, unsigned long long> factors;

    for (unsigned int i {0}; i < m; ++i)
    {
        if (!factors[divisors[i]])
        {
            factors[divisors[i]] = 1;
        }

        factors[divisors[i]] = (factors[divisors[i]] * coefficients[i]) % modulo;
    }

    for (const auto& divisor_and_factor : factors)
    {
        unsigned int       divisor {divisor_and_factor.first};
        unsigned long long factor  {divisor_and_factor.second};

        for (unsigned int i {divisor - 1}; i < n; i += divisor)
        {
            integers[i] = (integers[i] * factor) % modulo;
        }
    }

    for (unsigned int i {0}; i < n; ++i)
    {
        cout << integers[i];

        if (i < n - 1)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
