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

    unsigned int soldiers;
    unsigned int reports;

    while (cin >> soldiers >> reports && !(soldiers == 0 && reports == 0))
    {
        vector<pair<unsigned int, unsigned int>> buddies(soldiers + 2);

        for (unsigned int i {1}; i <= soldiers; ++i)
        {
            buddies[i].first  = i - 1;
            buddies[i].second = i + 1;
        }

        for (unsigned int i {0}; i < reports; ++i)
        {
            unsigned int left;
            unsigned int right;

            cin >> left >> right;

            buddies[buddies[left].first].second  = buddies[right].second;
            buddies[buddies[right].second].first = buddies[left].first;

            if (buddies[buddies[right].second].first == 0)
            {
                cout << '*';
            }
            else
            {
                cout << buddies[buddies[right].second].first;
            }

            cout << ' ';

            if (buddies[buddies[left].first].second == soldiers + 1)
            {
                cout << '*';
            }
            else
            {
                cout << buddies[buddies[left].first].second;
            }

            cout << '\n';
        }

        cout << "-\n";
    }

    return 0;
}
