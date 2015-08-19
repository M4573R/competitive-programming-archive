#include <iostream>
#include <set>
#include <string>

using namespace std;

const set<char> vowels {'a', 'e', 'i', 'o', 'u'};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string sentence;
    getline(cin, sentence);

    for (auto i = sentence.cbegin(); i != sentence.cend(); ++i)
    {
        cout << *i;

        if (vowels.count(*i))
        {
            i += 2;
        }
    }

    cout << '\n';

    return 0;
}
