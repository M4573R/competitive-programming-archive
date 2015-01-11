#include <iostream>
#include <set>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int stores;
    cin >> stores;
    cin.get();

    set<string>  visited_brands;
    unsigned int skipped_stores {0};

    for (unsigned int i {0}; i < stores; ++i)
    {
        string brand;
        getline(cin, brand);

        if (visited_brands.count(brand))
        {
            ++skipped_stores;
        }
        else
        {
            visited_brands.insert(brand);
        }
    }

    cout << skipped_stores << '\n';

    return 0;
}
