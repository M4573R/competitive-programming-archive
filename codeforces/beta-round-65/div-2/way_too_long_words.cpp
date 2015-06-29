#include <iostream>
#include <string>

using namespace std;

constexpr unsigned int normal_word_limit {10};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int words_count;
    cin >> words_count;

    for (unsigned int i {0}; i < words_count; ++i)
    {
        string word;
        cin >> word;

        if (word.length() > normal_word_limit)
        {
            cout << word.front() << word.length() - 2 << word.back() << '\n';
        }
        else
        {
            cout << word << '\n';
        }
    }

    return 0;
}
