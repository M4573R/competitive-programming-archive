#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> in_words {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
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

    unsigned int lower;
    unsigned int upper;

    cin >> lower >> upper;

    for (unsigned int i {lower}; i <= upper; ++i)
    {
        if (i <= 9)
        {
            cout << in_words[i - 1];
        }
        else
        {
            cout << (i % 2 ? "odd" : "even");
        }

        cout << '\n';
    }

    return 0;
}
