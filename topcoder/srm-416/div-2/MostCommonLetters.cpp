#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <utility>

bool by_frequency(const pair<char, unsigned int>& left,
                  const pair<char, unsigned int>& right)
{
    return left.second < right.second;
}

class MostCommonLetters
{
public:
    string listMostCommon(vector<string> text)
    {
        map<char, unsigned int> frequencies;

        for (string line : text)
        {
            for (char symbol : line)
            {
                if (isalpha(symbol))
                {
                    ++frequencies[symbol];
                }
            }
        }

        unsigned int max_frequency {max_element(frequencies.cbegin(),
                                                frequencies.cend(),
                                                by_frequency)->second};

        string most_frequent;

        for (auto i = frequencies.cbegin(); i != frequencies.cend(); ++i)
        {
            if (i->second == max_frequency)
            {
                most_frequent += i->first;
            }
        }

        return most_frequent;
    }
};
