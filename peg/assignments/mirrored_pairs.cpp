#include <iostream>
#include <set>
#include <string>

using namespace std;

const set<string> mirrored_pairs {"pq", "qp", "bd", "db"};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    cout << "Ready\n";

    for (string pair; getline(cin, pair) && pair != "  "; )
    {
        if (mirrored_pairs.count(pair))
        {
            cout << "Mirrored";
        }
        else
        {
            cout << "Ordinary";
        }

        cout << " pair\n";
    }

    return 0;
}
