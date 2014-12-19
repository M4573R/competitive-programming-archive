#include <iostream>
#include <map>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    map<string, unsigned int> country_conquests;

    unsigned int conquests;
    cin >> conquests;

    for (unsigned int i {0}; i < conquests; ++i)
    {
        string country;
        string woman;

        cin >> country;
        getline(cin, woman);

        ++country_conquests[country];
    }

    for (const auto& country_and_conquests : country_conquests)
    {
        cout << country_and_conquests.first  << ' '
             << country_and_conquests.second << '\n';
    }

    return 0;
}
