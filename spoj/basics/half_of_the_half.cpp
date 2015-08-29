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
    cin.ignore();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string sequence;
        getline(cin, sequence);

        for (string::size_type i {0}; i < sequence.size() / 2; i += 2)
        {
            cout << sequence[i];
        }

        cout << '\n';
    }

    return 0;
}
