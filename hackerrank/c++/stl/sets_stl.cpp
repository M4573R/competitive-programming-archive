#include <iostream>
#include <set>

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

    unsigned int queries;
    cin >> queries;

    set<unsigned int> elements;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int type;
        unsigned int element;

        cin >> type >> element;

        if (type == 1)
        {
            elements.insert(element);
        }
        else if (type == 2)
        {
            elements.erase(element);
        }
        else
        {
            cout << (elements.count(element) ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}
