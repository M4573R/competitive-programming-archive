#include <iostream>
#include <map>
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

    for (unsigned int numbers, queries; cin >> numbers >> queries; )
    {
        map<unsigned int, vector<unsigned int>> occurrences;

        for (unsigned int i {0}; i < numbers; ++i)
        {
            unsigned int number;
            cin >> number;

            occurrences[number].push_back(i);
        }

        for (unsigned int i {0}; i < queries; ++i)
        {
            unsigned int occurrence;
            unsigned int number;

            cin >> occurrence >> number;

            if (occurrences[number].size() < occurrence)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << occurrences[number][occurrence - 1] + 1 << '\n';
            }
        }
    }

    return 0;
}
