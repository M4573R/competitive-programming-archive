#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Hyphenated
{
public:
    double avgLength(vector<string> lines)
    {
        int letters {0};
        int words   {0};

        for (int i {0}; i < lines.size(); ++i)
        {
            for (int j {0}; j < lines[i].size(); ++j)
            {
                if (isalpha(lines[i][j]))
                {
                    ++letters;

                    if (!is_next_letter(lines, i, j) &&
                        !is_hyphenated (lines, i, j))
                    {
                        ++words;
                    }
                }
            }
        }

        return static_cast<double>(letters) / words;
    }

private:

    bool is_next_letter(const vector<string>& lines, int i, int j)
    {
        return j + 1 < lines[i].size() && isalpha(lines[i][j + 1]);
    }

    bool is_hyphenated(const vector<string>& lines, int i, int j)
    {
        return (j + 2 == lines[i].size() &&
                lines[i][j + 1] == '-'   &&
                i + 1 < lines.size()     &&
                isalpha(lines[i + 1].front()));
    }
};
