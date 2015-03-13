#include <iostream>

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

    unsigned int lines;
    cin >> lines;
    cin.ignore();

    unsigned int s_count {0};
    unsigned int t_count {0};

    for (unsigned int i {0}; i < lines; ++i)
    {
        string line;
        getline(cin, line);

        for (auto symbol : line)
        {
            if (symbol == 's' || symbol == 'S')
            {
                ++s_count;
            }

            if (symbol == 't' || symbol == 'T')
            {
                ++t_count;
            }
        }
    }

    cout << (s_count < t_count ? "English" : "French") << '\n';

    return 0;
}
