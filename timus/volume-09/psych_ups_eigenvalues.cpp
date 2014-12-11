#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
inline vector<T> intersect(const vector<T>& left, const vector<T>& right)
{
    vector<T> intersection;

    set_intersection(left.begin(),
                     left.end(),
                     right.begin(),
                     right.end(),
                     inserter(intersection, intersection.begin()));

    return intersection;
}

int main()
{
    use_io_optimizations();

    vector<vector<unsigned int>> all_eigenvalues;

    for (unsigned int eigenvalues_count; cin >> eigenvalues_count; )
    {
        all_eigenvalues.push_back(vector<unsigned int>(eigenvalues_count));

        for (auto& eigenvalue : all_eigenvalues.back())
        {
            cin >> eigenvalue;
        }
    }

    vector<unsigned int> team_eigenvalues {all_eigenvalues.front()};

    for (const auto& eigenvalues : all_eigenvalues)
    {
        team_eigenvalues = intersect(team_eigenvalues, eigenvalues);
    }

    cout << team_eigenvalues.size() << '\n';

    return 0;
}
