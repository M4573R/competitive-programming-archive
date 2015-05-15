#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int max_length {100000};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> maximums(unsigned int length)
{
    vector<unsigned int> sequence(max_length);
    vector<unsigned int> max_up_to(max_length);

    sequence[0] = max_up_to[0] = 0;
    sequence[1] = max_up_to[1] = 1;

    for (unsigned int i = 2; i < max_length; ++i)
    {
        if (i % 2 == 0)
        {
            sequence[i] = sequence[i / 2];
        }
        else
        {
            sequence[i] = sequence[i / 2] + sequence[i / 2 + 1];
        }

        max_up_to[i] = max(max_up_to[i - 1], sequence[i]);
    }

    return max_up_to;
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> max_up_to {maximums(max_length)};

    for (unsigned int length; cin >> length && length != 0; )
    {
        cout << max_up_to[length] << '\n';
    }

    return 0;
}
