#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool is_number(const string& sequence)
{
    return sequence.find_first_not_of("0123456789") == string::npos;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        char delimiter;

        string left;
        string right;
        string sum;

        cin >> left  >> delimiter
            >> right >> delimiter
            >> sum;

        cout << (is_number(left)  ? stoi(left)  : stoi(sum)  - stoi(right))
             << " + "
             << (is_number(right) ? stoi(right) : stoi(sum)  - stoi(left))
             << " = "
             << (is_number(sum)   ? stoi(sum)   : stoi(left) + stoi(right))
             << '\n';
    }

    return 0;
}
