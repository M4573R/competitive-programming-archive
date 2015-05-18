#include <iostream>
#include <set>
#include <string>
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

    unsigned int count;
    cin >> count;

    string sequence;
    cin >> sequence;

    set<char> letters;
    vector<unsigned int> indices;

    for (unsigned int i {0}; i < sequence.size() && indices.size() < count; ++i)
    {
        if (!letters.count(sequence[i]))
        {
            indices.push_back(i);
            letters.insert(sequence[i]);
        }
    }

    if (indices.size() == count)
    {
        cout << "YES\n";

        indices.push_back(sequence.size());

        for (unsigned int i {0}; i < count; ++i)
        {
            cout << sequence.substr(indices[i], indices[i + 1] - indices[i]) << '\n';
        }
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
