#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr unsigned int locations {5};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<vector<unsigned int>> distances(locations,
                                           vector<unsigned int>(locations));

    for (unsigned int from {0}; from < locations; ++from)
    {
        for (unsigned int to {0}; to < locations; ++to)
        {
            cin >> distances[from][to];
        }
    }

    const map<unsigned int, vector<unsigned int>> length_to_path {
        {distances[0][1] +
         distances[1][2] +
         distances[2][3] +
         distances[3][4],  {1, 2, 3, 4, 5}},

        {distances[0][2] +
         distances[2][1] +
         distances[1][3] +
         distances[3][4],  {1, 3, 2, 4, 5}},

        {distances[0][2] +
         distances[2][3] +
         distances[3][1] +
         distances[1][4],  {1, 3, 4, 2, 5}},

        {distances[0][3] +
         distances[3][2] +
         distances[2][1] +
         distances[1][4],  {1, 4, 3, 2, 5}}
    };

    auto optimal_solution = min_element(length_to_path.cbegin(),
                                        length_to_path.cend());

    auto optimal_length   = optimal_solution->first;
    auto optimal_path     = optimal_solution->second;

    cout << optimal_length << '\n';

    for (unsigned int i {0}; i < locations; ++i)
    {
        cout << optimal_path[i];

        if (i < locations - 1)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
