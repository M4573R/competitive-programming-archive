#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int insert(vector<map<char, unsigned int>>& trie, const string& word)
{
    unsigned int node  {0};
    unsigned int typed {0};
    bool in_new_banch  {false};

    for (auto letter : word)
    {
        if (!in_new_banch)
        {
            ++typed;
        }

        if (!trie[node].count(letter))
        {
            trie[node][letter] = trie.size();
            trie.emplace_back();
            in_new_banch = true;
        }

        node = trie[node][letter];
    }

    return typed;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int words;
        cin >> words;

        unsigned int typed {0};
        vector<map<char, unsigned int>> trie(1);

        for (unsigned int i {0}; i < words; ++i)
        {
            string word;
            cin >> word;

            typed += insert(trie, word);
        }

        cout << "Case #" << test << ": " << typed << '\n';
    }

    return 0;
}
