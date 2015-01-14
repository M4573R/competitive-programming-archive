#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int bits_count {7};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline bool is_hamming(const vector<int>& bits)
{
    return ((bits[1] + bits[2] + bits[3]) % 2 == bits[4] &&
            (bits[0] + bits[2] + bits[3]) % 2 == bits[5] &&
            (bits[0] + bits[1] + bits[3]) % 2 == bits[6]);
}

int main()
{
    use_io_optimizations();

    vector<int> bits(bits_count);

    for (auto& bit : bits)
    {
        cin >> bit;
    }

    for (unsigned int i {0}; i < bits_count && !is_hamming(bits); ++i)
    {
        bits[i] = !bits[i];

        if (!is_hamming(bits))
        {
            bits[i] = !bits[i];
        }
    }

    for (unsigned int i {0}; i < bits_count; ++i)
    {
        cout << bits[i];

        if (i < bits_count - 1)
        {
            cout << ' ';
        }
    }

    cout << '\n';

    return 0;
}
