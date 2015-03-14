#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

constexpr unsigned int modulo {1000000007};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long exponentiate(long long base,
                       unsigned long long exponent,
                       unsigned long long modulo)
{
    long long result    {1};
    long long aggregate {base};

    for (unsigned long long i {exponent}; i > 0; i /= 2)
    {
        if (i % 2 == 1)
        {
            result = (result * aggregate) % modulo;
        }

        aggregate = (aggregate * aggregate) % modulo;
    }

    return result;
}

int main()
{
    use_io_optimizations();

    unsigned int length;
    cin >> length;

    string sequence;
    cin >> sequence;

    map<char, unsigned int> frequencies;

    for (auto symbol : sequence)
    {
        ++frequencies[symbol];
    }

    map<unsigned int, unsigned int, greater<unsigned int>> frequency_count;

    for (const auto& symbol_and_frequency : frequencies)
    {
        ++frequency_count[symbol_and_frequency.second];
    }

    cout << exponentiate(frequency_count.cbegin()->second, length, modulo) << '\n';

    return 0;
}
