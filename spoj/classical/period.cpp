#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> fail_links(const string& pattern)
{
    vector<unsigned int> links(pattern.size());

    for (unsigned int i {1}, j {0}; i < pattern.size(); ++i)
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

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {1}; test <= test_cases; ++test)
    {
        unsigned int size;
        cin >> size;

        string text;
        cin >> text;

        vector<unsigned int> links {fail_links(text)};

        cout << "Test case #" << test << '\n';

        for (unsigned int i {1}; i < links.size(); ++i)
        {
            unsigned int prefix_size {i + 1};
            unsigned int prefix_link {links[i]};

            if (prefix_size % (prefix_size - prefix_link) == 0)
            {
                unsigned int period {prefix_size / (prefix_size - prefix_link)};

                if (period > 1)
                {
                    cout << prefix_size << ' ' << period << '\n';
                }
            }
        }

        cout << '\n';
    }

    return 0;
}
