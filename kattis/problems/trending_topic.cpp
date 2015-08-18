#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct FrequencyComparison
{
    bool operator()(const pair<string, unsigned int>& left,
                    const pair<string, unsigned int>& right)
    {
        if (left.second == right.second)
        {
            return left.first < right.first;
        }

        return left.second > right.second;
    }
};

void read_text(queue<vector<string>>& days,
               unordered_map<string, unsigned int>& frequencies)
{
    vector<string> day;

    for (string word; cin >> word && word != "</text>"; )
    {
        if (word.size() >= 4)
        {
            day.push_back(word);
            ++frequencies[word];
        }
    }

    days.push(day);

    if (days.size() > 7)
    {
        for (const auto& word : days.front())
        {
            --frequencies[word];
        }

        days.pop();
    }
}

vector<pair<string, unsigned int>>
sorted_frequencies(const unordered_map<string, unsigned int>& frequencies)
{
    vector<pair<string, unsigned int>> sorted;

    for (const auto& frequency : frequencies)
    {
        if (frequency.second)
        {
            sorted.push_back(frequency);
        }
    }

    sort(sorted.begin(), sorted.end(), FrequencyComparison());

    return sorted;
}

void print_top(const vector<pair<string, unsigned int>>& frequencies,
               unsigned int top)
{
    cout << "<top " << top << ">\n";

    auto i = frequencies.cbegin();

    for (; i != frequencies.cend() && i != frequencies.cbegin() + top; ++i)
    {
        cout << i->first << ' ' << i->second << '\n';
    }

    for (; i != frequencies.cend() && i->second == (i - 1)->second; ++i)
    {
        cout << i->first << ' ' << i->second << '\n';
    }

    cout << "</top>\n";
}

int main()
{
    use_io_optimizations();

    queue<vector<string>> days;
    unordered_map<string, unsigned int> frequencies;

    for (string word; cin >> word; )
    {
        if (word == "<text>")
        {
            read_text(days, frequencies);
        }
        else
        {
            unsigned int top;
            cin >> top >> word;

            print_top(sorted_frequencies(frequencies), top);
        }
    }

    return 0;
}
