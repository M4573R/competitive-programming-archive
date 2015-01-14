#include <iostream>
#include <string>
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

    unsigned int hieroglyphs_count;
    cin >> hieroglyphs_count;

    vector<string> hieroglyphs(hieroglyphs_count);

    for (auto& hieroglyph : hieroglyphs)
    {
        cin >> hieroglyph;
    }

    char first_letter;
    cin >> first_letter;

    for (const auto& hieroglyph : hieroglyphs)
    {
        if (hieroglyph.front() == first_letter)
        {
            cout << hieroglyph << '\n';
        }
    }

    return 0;
}
