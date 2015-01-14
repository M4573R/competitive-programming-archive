#include <iostream>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int page_size;
    unsigned int line_size;
    unsigned int words;

    cin >> page_size >> line_size >> words;

    unsigned int page         {1};
    unsigned int line         {1};
    unsigned int line_positon {0};

    for (unsigned int i {0}; i < words; ++i)
    {
        string word;
        cin >> word;

        line_positon += word.size() + 1;

        if (line_positon > line_size + 1)
        {
            line_positon = word.size() + 1;
            ++line;

            if (line > page_size)
            {
                line = 1;
                ++page;
            }
        }
    }

    cout << page << '\n';

    return 0;
}
