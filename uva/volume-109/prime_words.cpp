#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<char> eratosthenes_sieve(unsigned int up_to)
{
    vector<char> sieve(up_to + 1, 1);
    sieve[0] = 0;

    for (vector<char>::size_type i {4}; i < sieve.size(); i += 2)
    {
        sieve[i] = 0;
    }

    unsigned int upper_bound = sqrt(sieve.size());

    for (vector<char>::size_type i {3}; i < upper_bound; i += 2)
    {
        if (sieve[i] == 1)
        {
            for (auto j = i * i; j < sieve.size(); j += 2 * i)
            {
                sieve[j] = 0;
            }
        }
    }

    return sieve;
}

constexpr unsigned int lower_a_value {1}
constexpr unsigned int upper_a_value {27};

unsigned int word_sum(const string& word)
{
    unsigned int sum {0};

    for (auto letter : word)
    {
        if (islower(letter))
        {
            sum += letter - 'a' + lower_a_value;
        }
        else if (isupper(letter))
        {
            sum += letter - 'A' + upper_a_value;
        }
    }

    return sum;
}

inline bool is_prime_word(const string& word)
{
    static const vector<char> sieve {eratosthenes_sieve(max_word_sum + 1)};

    return sieve[word_sum(word)] == 1;
}

constexpr unsigned int max_word_length {20};
constexpr unsigned int max_word_sum    {max_word_length * 52};

int main()
{
    use_io_optimizations();

    string word;

    while (cin >> word)
    {
        if (is_prime_word(word))
        {
            cout << "It is a prime word.";
        }
        else
        {
            cout << "It is not a prime word.";
        }

        cout << '\n';
    }

    return 0;
}
