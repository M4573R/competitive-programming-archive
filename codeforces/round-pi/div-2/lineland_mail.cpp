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

    unsigned int cities;
    cin >> cities;

    vector<int> coordinates(cities);

    for (auto& coordinate : coordinates)
    {
        cin >> coordinate;
    }

    for (auto i = coordinates.cbegin(); i != coordinates.cend(); ++i)
    {
        if (i == coordinates.cbegin())
        {
            cout << *(i + 1) - *i << ' ';
        }
        else if (i == coordinates.cend() - 1)
        {
            cout << *i - *(i - 1) << ' ';
        }
        else
        {
            cout << min(*i - *(i - 1), *(i + 1) - *i) << ' ';
        }

        cout << max(*i - coordinates.front(), coordinates.back() - *i) << '\n';
    }

    return 0;
}
