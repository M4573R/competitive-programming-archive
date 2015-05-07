#include <algorithm>
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

unsigned int min_palindrome(const string& text, const string& pattern)
{
    vector<unsigned int> links = fail_links(pattern);

    unsigned int j = 0;

    for (unsigned int i = 0; i < text.size(); ++i)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = links[j - 1];
        }

        if (text[i] == pattern[j])
        {
            ++j;
        }
    }

    return 2 * text.size() - j;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        string text;
        cin >> text;

        string pattern = text;
        reverse(pattern.begin(), pattern.end());

        cout << "Case " << test << ": " << min_palindrome(text, pattern) << '\n';
    }

    return 0;
}
