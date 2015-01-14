#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int alphabet_size {26};

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    vector<unsigned int> frequencies(alphabet_size);

    for (char letter; cin >> letter; )
    {
        ++frequencies[letter - 'a'];
    }

    unsigned int odd_frequencies {0};

    for (auto frequency : frequencies)
    {
        odd_frequencies += frequency % 2;
    }

    cout << (odd_frequencies <= 1 ? "YES" : "NO") << '\n';

    return 0;
}
