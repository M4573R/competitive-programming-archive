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

    char         best_spell;
    unsigned int best_spell_power {0};

    vector<unsigned int> frequencies(alphabet_size);

    for (char letter; cin >> letter; )
    {
        ++frequencies[letter - 'a'];

        if (frequencies[letter - 'a'] > best_spell_power)
        {
            best_spell_power = frequencies[letter - 'a'];
            best_spell       = letter;
        }
    }

    cout << best_spell << '\n';

    return 0;
}
