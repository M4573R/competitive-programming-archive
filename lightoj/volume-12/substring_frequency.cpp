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

unsigned int matches_count(const string& text, const string& pattern)
{
    unsigned int matches       = 0;
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
            ++matches;
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

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        string text;
        string pattern;

        cin >> text >> pattern;

        cout << "Case " << test << ": " << matches_count(text, pattern) << '\n';
    }

    return 0;
}
