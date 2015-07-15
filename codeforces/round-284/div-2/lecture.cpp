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

    unsigned int lecture_size;
    unsigned int dictionary_size;

    cin >> lecture_size >> dictionary_size;

    map<string, string> dictionary;

    for (unsigned int i {0}; i < dictionary_size; ++i)
    {
        string word;
        cin >> word;
        cin >> dictionary[word];
    }

    for (unsigned int i {0}; i < lecture_size; ++i)
    {
        string word;
        cin >> word;

        if (word.size() <= dictionary[word].size())
        {
            cout << word;
        }
        else
        {
            cout << dictionary[word];
        }

        cout << " \n"[i + 1 == lecture_size];
    }

    return 0;
}
