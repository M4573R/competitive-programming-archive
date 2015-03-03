#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

map<char, unsigned int> read_values()
{
    unsigned int paid_characters;
    cin >> paid_characters;

    map<char, unsigned int> values;

    for (unsigned int i {0}; i < paid_characters; ++i)
    {
        char character;
        unsigned int value;

        cin >> character >> value;

        values[character] = value;
    }

    return values;
}

unsigned int find_article_value()
{
    map<char, unsigned int> values {read_values()};

    unsigned int lines;
    cin >> lines;
    cin.ignore();

    unsigned int article_value {0};

    for (unsigned int i {0}; i < lines; ++i)
    {
        string line;
        getline(cin, line);

        for (auto character : line)
        {
            article_value += values[character];
        }
    }

    return article_value;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int article_value {find_article_value()};
        unsigned int dollars       {article_value / 100};
        unsigned int cents         {article_value % 100};

        cout << dollars << '.' << setfill('0') << setw(2) << cents << "$\n";
    }

    return 0;
}
