#include <iostream>
#include <string>
#include <unordered_map>

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

    unsigned int words;
    unsigned int descriptions;

    cin >> words >> descriptions;

    unordered_map<string, unsigned int> dictionary;

    for (unsigned int i {0}; i < words; ++i)
    {
        string word;
        unsigned int dollars;

        cin >> word >> dollars;

        dictionary[word] = dollars;
    }

    for (unsigned int i {0}; i < descriptions; ++i)
    {
        unsigned int salary {0};

        for (string word; cin >> word && word != "."; )
        {
            salary += dictionary[word];
        }

        cout << salary << '\n';
    }

    return 0;
}
