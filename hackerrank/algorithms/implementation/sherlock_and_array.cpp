#include <iostream>
#include <vector>

using namespace std;

inline void use_io_optimizations()
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
        unsigned int size;
        cin >> size;

        vector<unsigned long long> prefix_sums(size + 1);

        for (unsigned int i {1}; i <= size; ++i)
        {
            unsigned int element;
            cin >> element;

            prefix_sums[i] = prefix_sums[i - 1] + element;
        }

        bool exists {false};

        for (unsigned int i {1}; i <= size && !exists; ++i)
        {
            if (prefix_sums[i - 1] == prefix_sums[size] - prefix_sums[i])
            {
                exists = true;
            }
        }

        cout << (exists ? "YES" : "NO") << '\n';
    }

    return 0;
}
