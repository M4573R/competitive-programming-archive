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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int pile_size;
        cin >> pile_size;

        string first_pile;
        string second_pile;

        cin >> first_pile >> second_pile;

        for (unsigned int i {pile_size}; i-- > 0; )
        {
            cout << second_pile[i] << first_pile[i];
        }

        cout << '\n';
    }

    return 0;
}
