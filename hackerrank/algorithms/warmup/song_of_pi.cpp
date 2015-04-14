#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const vector<unsigned int> pi {
    3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9,
    3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 3
};

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
    cin.ignore();

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string line;
        getline(cin, line);

        string word;
        istringstream song {line};

        bool is_pi_song {true};

        for (unsigned int i {0}; song >> word; ++i)
        {
            if (pi[i] != word.length())
            {
                is_pi_song = false;
            }
        }

        cout << "It's " << (is_pi_song ? "" : "not ") << "a pi song.\n";
    }

    return 0;
}
