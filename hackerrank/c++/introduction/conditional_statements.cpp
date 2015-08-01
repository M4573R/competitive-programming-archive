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

    unsigned int number;
    cin >> number;

    if (number <= 9)
    {
        cout << in_words[number - 1];
    }
    else
    {
        cout << "Greater than 9";
    }

    cout << '\n';

    return 0;
}
