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

int main()
{
    use_io_optimizations();

    string sequence;
    cin >> sequence;

    unsigned int additional;
    cin >> additional;

    unsigned int max_value {0};
    vector<unsigned int> values(26);

    for (auto& value : values)
    {
        cin >> value;
        max_value = max(max_value, value);
    }

    unsigned int sequence_value {0};

    for (string::size_type i {0}; i < sequence.size(); ++i)
    {
        sequence_value += (i + 1) * values[sequence[i] - 'a'];
    }

    for (unsigned int i {1}; i <= additional; ++i)
    {
        sequence_value += (sequence.size() + i) * max_value;
    }

    cout << sequence_value << '\n';

    return 0;
}
