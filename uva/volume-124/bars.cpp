#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool could_be_made(const vector<unsigned int>& lengths, unsigned int target)
{
    vector<bool> is_possible(target + 1);

    is_possible[0] = true;

    for (auto length : lengths)
    {
        for (unsigned int i {target}; i >= length; --i)
        {
            if (!is_possible[i] && is_possible[i - length])
            {
                is_possible[i] = true;
            }
        }
    }

    return is_possible[target];
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int target;
        unsigned int bars;

        cin >> target >> bars;

        vector<unsigned int> lengths(bars);

        for (auto& length : lengths)
        {
            cin >> length;
        }

        cout << (could_be_made(lengths, target) ? "YES" : "NO") << '\n';
    }

    return 0;
}
