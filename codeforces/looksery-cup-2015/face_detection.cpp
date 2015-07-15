#include <algorithm>
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

int main()
{
    use_io_optimizations();

    unsigned int height;
    unsigned int width;

    cin >> height >> width;

    vector<string> image(height);

    for (auto& row : image)
    {
        cin >> row;
    }

    unsigned int faces {0};

    for (unsigned int i {0}; i < height - 1; ++i)
    {
        for (unsigned int j {0}; j < width - 1; ++j)
        {
            string square {image[i].substr(j, 2) + image[i + 1].substr(j, 2)};

            sort(square.begin(), square.end());

            if (square == "acef")
            {
                ++faces;
            }
        }
    }

    cout << faces << '\n';

    return 0;
}
