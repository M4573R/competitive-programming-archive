#include <iostream>
#include <string>

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

    string first;
    string second;

    cin >> first >> second;

    unsigned int distance {0};
    string equidistant;

    for (string::size_type i {0}; i < first.size(); ++i)
    {
        if (first[i] == second[i])
        {
            equidistant += '0';
        }
        else
        {
            if (distance % 2)
            {
                equidistant += first[i];
            }
            else
            {
                equidistant += second[i];
            }

            ++distance;
        }
    }

    cout << (distance % 2 ? "impossible" : equidistant) << "\n";

    return 0;
}
