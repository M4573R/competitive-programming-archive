#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_input(vector<unsigned int>& first,
                vector<unsigned int>& second)
{
    unsigned int first_size;
    unsigned int second_size;

    cin >> first_size >> second_size;

    first.resize(first_size);

    for (auto& strength : first)
    {
        cin >> strength;
    }

    second.resize(second_size);

    for (auto& strength : second)
    {
        cin >> strength;
    }
}

void write_output(const vector<unsigned int>& first,
                  const vector<unsigned int>& second)
{
    if (*max_element(first .cbegin(), first .cend()) <
        *max_element(second.cbegin(), second.cend()))
    {
        cout << "MechaGodzilla\n";
    }
    else
    {
        cout << "Godzilla\n";
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        vector<unsigned int> first;
        vector<unsigned int> second;

        read_input  (first, second);
        write_output(first, second);
    }

    return 0;
}
