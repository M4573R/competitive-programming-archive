#include <iostream>

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

    unsigned int test_cases;
    cin >> test_cases;
    cin.ignore();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string pieces;
        getline(cin, pieces);

        unsigned int male   {0};
        unsigned int female {0};

        for (auto connector : pieces)
        {
            if (connector == 'M')
            {
                ++male;
            }
            else if (connector == 'F')
            {
                ++female;
            }
        }

        cout << (male == female && male > 1 ? "LOOP" : "NO LOOP") << '\n';
    }

    return 0;
}
