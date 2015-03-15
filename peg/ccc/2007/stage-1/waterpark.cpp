#include <algorithm>
#include <iostream>
#include <utility>
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

    unsigned int points;
    cin >> points;

    vector<pair<unsigned int, unsigned int>> slides;

    for (unsigned int from, to; cin >> from >> to && !(from == 0 && to == 0); )
    {
        slides.emplace_back(to, from);
    }

    sort(slides.begin(), slides.end());

    vector<unsigned int> ways(points + 1);
    ways[1] = 1;

    for (const auto& slide : slides)
    {
        ways[slide.first] += ways[slide.second];
    }

    cout << ways[points] << '\n';

    return 0;
}
