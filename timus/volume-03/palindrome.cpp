#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr char special_character {'#'};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string preprocess(const string& text)
{
    string amended {'^'};

    for (auto character : text)
    {
        amended += special_character;
        amended += character;
    }

    amended += "#$";

    return amended;
}

vector<string::size_type> palindrome_lengths(const string& text)
{
    vector<string::size_type> lengths(text.size());

    string::size_type center {0};
    string::size_type right  {0};

    for (string::size_type i {1}; i < text.size() - 1; ++i)
    {
        string::size_type mirror {2 * center - i};

        lengths[i] = (right > i ? min(right - i, lengths[mirror]) : 0);

        while (text[i + 1 + lengths[i]] == text[i - 1 - lengths[i]])
        {
            ++lengths[i];
        }

        if (i + lengths[i] > right)
        {
            center = i;
            right  = i + lengths[i];
        }
    }

    return lengths;
}

string longest_palindrome(const string& text)
{
    if (text.size() == 0)
    {
        return "";
    }

    vector<string::size_type> lengths {palindrome_lengths(preprocess(text))};

    auto max_length   = max_element(lengths.cbegin(), lengths.cend());
    auto center_index = max_length - lengths.cbegin();
    auto start_index  = (center_index - 1 - *max_length) / 2;

    return text.substr(start_index, *max_length);
}

int main()
{
    use_io_optimizations();

    string text;
    cin >> text;

    cout << longest_palindrome(text) << '\n';

    return 0;
}
