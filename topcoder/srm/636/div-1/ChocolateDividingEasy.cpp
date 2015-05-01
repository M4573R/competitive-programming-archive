#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ChocolateDividingEasy
{
public:
    static constexpr int quality_upper_bound {1000000000};

    int findBest(vector<string> chocolate)
    {
        vector<vector<int>> sub_qualities {calculateSubQualities(chocolate)};
        int best_mirosz_part {0};

        int height = chocolate.size();
        int width  = chocolate.front().size();

        for (int i {1}; i < height - 1; ++i)
        {
            for (int j {i + 1}; j < height; ++j)
            {
                for (int x {1}; x < width - 1; ++x)
                {
                    for (int y {x + 1}; y < width; ++y)
                    {
                        vector<int> horizontal_cuts {0, i, j, height};
                        vector<int> vertical_cuts   {0, x, y, width};

                        best_mirosz_part = max(best_mirosz_part,
                                               findMinQuality(sub_qualities,
                                                              horizontal_cuts,
                                                              vertical_cuts));
                    }
                }
            }
        }

        return best_mirosz_part;
    }

private:
    vector<vector<int>> calculateSubQualities(const vector<string>& chocolate)
    {
        int height = chocolate.size();
        int width  = chocolate.front().size();

        vector<vector<int>> sub_qualities(height + 1, vector<int>(width + 1));

        for (int i {1}; i <= height; ++i)
        {
            for (int j {1}; j <= width; ++j)
            {
                int bar_quality {chocolate[i - 1][j - 1] - '0'};

                sub_qualities[i][j] = (bar_quality +
                                       sub_qualities[i - 1][j] +
                                       sub_qualities[i][j - 1] -
                                       sub_qualities[i - 1][j - 1]);
            }
        }

        return sub_qualities;
    }

    int findMinQuality(const vector<vector<int>>& sub_qualities,
                       const vector<int>& horizontal_cuts,
                       const vector<int>& vertical_cuts)
    {
        int min_quality {quality_upper_bound};

        for (int i {1}; i <= 3; ++i)
        {
            for (int j {1}; j <= 3; ++j)
            {
                int part_quality {
                    sub_qualities[horizontal_cuts[i]][vertical_cuts[j]] -
                    sub_qualities[horizontal_cuts[i - 1]][vertical_cuts[j]] -
                    sub_qualities[horizontal_cuts[i]][vertical_cuts[j - 1]] +
                    sub_qualities[horizontal_cuts[i - 1]][vertical_cuts[j - 1]]
                };

                min_quality = min(min_quality, part_quality);
            }
        }

        return min_quality;
    }
};
