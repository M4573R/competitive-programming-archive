#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Picture
{
    unsigned int width;
    unsigned int height;
};

bool fits(unsigned int width,
          unsigned int height,
          const Picture& first,
          const Picture& second)
{
    return (first.width + second.width <= width &&
            max(first.height, second.height) <= height);
}

int main()
{
    use_io_optimizations();

    unsigned int width;
    unsigned int height;

    cin >> width >> height;

    Picture first;
    Picture second;

    cin >> first.width  >> first.height
        >> second.width >> second.height;

    for (unsigned int i {0}; i < 2; ++i)
    {
        if (i == 1)
        {
            swap(first.width, first.height);
        }

        for (unsigned int j {0}; j < 2; ++j)
        {
            if (j == 1)
            {
                swap(second.width, second.height);
            }

            if (fits(width, height, first, second) ||
                fits(height, width, first, second))
            {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}
