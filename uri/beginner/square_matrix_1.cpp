#include <iomanip>
#include <iostream>
#include <vector>

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

    for (unsigned int lines_count; cin >> lines_count && lines_count > 0; )
    {
        vector<vector<unsigned int>> lines(lines_count);

        for (unsigned int i {1}; i <= (lines_count + 1) / 2; ++i)
        {
            vector<unsigned int> line;

            for (unsigned int j {1}; j < i; ++j)
            {
                line.push_back(j);
            }

            line.insert(line.end(), lines_count - 2 * (i - 1), i);

            for (unsigned int j {i - 1}; j >= 1; --j)
            {
                line.push_back(j);
            }

            lines[i - 1]           = line;
            lines[lines_count - i] = line;
        }

        for (const auto& line : lines)
        {
            for (auto i = line.cbegin(); i != line.cend(); ++i)
            {
                cout << setw(3) << *i << (i + 1 != line.cend() ? ' ' : '\n');
            }
        }

        cout << '\n';
    }

    return 0;
}
