#include <vector>

using namespace std;

class DevuAndBeautifulSubstrings
{
public:
    long long countBeautifulSubstrings(int n, int cnt)
    {
        vector<vector<long long>> subtasks(n + 1, vector<long long>(cnt + 1));

        subtasks[0][0] = 2;

        for (int i {0}; i < n; ++i)
        {
            for (int j {0}; j < cnt; ++j)
            {
                for (int length {1}; length <= n - i; ++length)
                {
                    int beauty {length * (length + 1) / 2};

                    if (j + beauty <= cnt)
                    {
                        subtasks[i + length][j + beauty] += subtasks[i][j];
                    }
                }
            }
        }

        return subtasks[n][cnt];
    }
};
