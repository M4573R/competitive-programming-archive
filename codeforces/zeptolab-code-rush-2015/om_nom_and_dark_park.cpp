#include <algorithm>
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

    unsigned int height;
    cin >> height;

    vector<unsigned int> lights(1 << (height + 1));

    for (unsigned int i {2}; i < lights.size(); ++i)
    {
        cin >> lights[i];
    }

    unsigned int new_lights {0};

    for (unsigned int i {(1u << height) - 1}; i >= 1; --i)
    {
        unsigned int left  {lights[2 * i]};
        unsigned int right {lights[2 * i + 1]};

        lights[i]  += max(left, right);
        new_lights += 2 * max(left, right) - left - right;
    }

    cout << new_lights << '\n';

    return 0;
}
