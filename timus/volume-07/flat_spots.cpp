#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int min_diameter {600};
constexpr unsigned int max_diameter {700};
constexpr unsigned int diameters    {101};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> diameters_count(diameters);

    unsigned int pairs;
    cin >> pairs;

    for (unsigned int i {0}; i < pairs; ++i)
    {
        unsigned int diameter;
        cin >> diameter;

        ++diameters_count[diameter - min_diameter];
    }

    unsigned int tram_sets {0};

    for (auto count : diameters_count)
    {
        tram_sets += count / 4;
    }

    cout << tram_sets << '\n';

    return 0;
}
