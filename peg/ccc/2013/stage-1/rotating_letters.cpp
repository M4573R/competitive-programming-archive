#include <iostream>
#include <set>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool can_be_used(const string& word)
{
    static const set<char> permitted_letters {
        'I', 'O', 'S', 'H', 'Z', 'X', 'N'
    };

    for (auto letter : word)
    {
        if (!permitted_letters.count(letter))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    string word;
    cin >> word;

    cout << (can_be_used(word) ? "YES" : "NO") << '\n';

    return 0;
}
