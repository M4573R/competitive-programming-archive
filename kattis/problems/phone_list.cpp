#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
        unsigned int numbers_count;
        cin >> numbers_count;

        vector<string> numbers(numbers_count);

        for (auto& number : numbers)
        {
            cin >> number;
        }

        sort(numbers.begin(), numbers.end());

        bool is_consistent {true};

        for (unsigned int i {0}; i < numbers_count - 1 && is_consistent; ++i)
        {
            if (numbers[i].size() <= numbers[i + 1].size() &&
                numbers[i] == numbers[i + 1].substr(0, numbers[i].size()))
            {
                is_consistent = false;
            }
        }

        cout << (is_consistent ? "YES" : "NO") << '\n';
    }

    return 0;
}
