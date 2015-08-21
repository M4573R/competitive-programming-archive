#include <iostream>
#include <map>
#include <string>

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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string sequence;
        cin >> sequence;

        map<map<char, unsigned int>, unsigned int> frequencies;

        for (string::size_type i {0}; i < sequence.size(); ++i)
        {
            map<char, unsigned int> key;

            for (string::size_type j {i}; j < sequence.size(); ++j)
            {
                ++key[sequence[j]];
                ++frequencies[key];
            }
        }

        unsigned int unordered_pairs {0};

        for (const auto& frequency : frequencies)
        {
            unordered_pairs += frequency.second * (frequency.second - 1) / 2;
        }

        cout << unordered_pairs << '\n';
    }

    return 0;
}
