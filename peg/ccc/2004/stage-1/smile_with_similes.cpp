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

    unsigned int adjectives_count;
    unsigned int nouns_count;

    cin >> adjectives_count >> nouns_count;

    vector<string> adjectives(adjectives_count);

    for (auto& adjective : adjectives)
    {
        cin >> adjective;
    }

    vector<string> nouns(nouns_count);

    for (auto& noun : nouns)
    {
        cin >> noun;
    }

    for (const auto& adjective : adjectives)
    {
        for (const auto& noun : nouns)
        {
            cout << adjective << " as " << noun << '\n';
        }
    }

    return 0;
}
