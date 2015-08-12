#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Rectangle
{
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
};

bool is_inside(const Rectangle& rectangle, unsigned int x, unsigned int y)
{
    return (x >= rectangle.x && x < rectangle.x + rectangle.width &&
            y >= rectangle.y && y < rectangle.y + rectangle.height);
}

int main()
{
    use_io_optimizations();

    unsigned int regions;
    unsigned int locations;

    cin >> regions >> locations;

    vector<Rectangle> rectangles(regions);

    for (auto& rectangle : rectangles)
    {
        cin >> rectangle.x     >> rectangle.y
            >> rectangle.width >> rectangle.height;
    }

    vector<bool> visited(regions);

    for (unsigned int i {0}; i < locations; ++i)
    {
        unsigned int x;
        unsigned int y;

        cin >> x >> y;

        for (unsigned int j {0}; j < regions; ++j)
        {
            if (is_inside(rectangles[j], x, y))
            {
                visited[j] = true;
            }
        }
    }

    cout << accumulate(visited.cbegin(), visited.cend(), 0) << '\n';

    return 0;
}
