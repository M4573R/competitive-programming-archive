#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<unsigned int> fail_links(const string& pattern)
{
    vector<unsigned int> links(pattern.size());

    for (unsigned int i = 1, j = 0; i < pattern.size(); ++i)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = links[j - 1];
        }

        if (pattern[i] == pattern[j])
        {
            ++j;
        }

        links[i] = j;
    }

    return links;
}

vector<unsigned int> find(const string& pattern, const string& text)
{
    vector<unsigned int> matches;
    vector<unsigned int> links = fail_links(pattern);

    for (unsigned int i = 0, j = 0; i < text.size(); ++i)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = links[j - 1];
        }

        if (text[i] == pattern[j])
        {
            ++j;
        }

        if (j == pattern.size())
        {
            matches.push_back(i - j + 1);
            j = links[j - 1];
        }
    }

    return matches;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int i {0}; i < test_cases; ++i)
    {
        string pattern;
        string text;

        cin >> pattern >> text;

        vector<unsigned int> matches = find(pattern, text);

        cout << matches.size() << '\n';

        for (unsigned int i = 0; i < matches.size(); ++i)
        {
            cout << matches[i] << (i < matches.size() - 1 ? ' ' : '\n');
        }
    }

    return 0;
}
