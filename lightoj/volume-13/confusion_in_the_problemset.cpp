#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool can_be_shuffled(const vector<unsigned int>& page_numbers)
{
    vector<unsigned int>::size_type pages = page_numbers.size();
    vector<bool> used(pages);

    for (unsigned int i = 0; i < pages; ++i)
    {
        if (page_numbers[i] >= pages)
        {
            return false;
        }

        if (!used[page_numbers[i]])
        {
            used[page_numbers[i]] = true;
        }
        else if (!used[pages - 1 - page_numbers[i]])
        {
            used[pages - 1 - page_numbers[i]] = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test = 1; test <= test_cases; ++test)
    {
        unsigned int pages;
        cin >> pages;

        vector<unsigned int> page_numbers(pages);

        for (unsigned int i = 0; i < pages; ++i)
        {
            cin >> page_numbers[i];
        }

        cout << "Case " << test << ": "
             << (can_be_shuffled(page_numbers) ? "yes" : "no") << '\n';
    }

    return 0;
}
