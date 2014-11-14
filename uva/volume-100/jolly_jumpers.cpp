#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_jolly_jumper(const vector<int>& sequence)
{
    set<int> jolly_jumper_contents;

    for (vector<int>::size_type i {1}; i < sequence.size(); ++i)
    {
        jolly_jumper_contents.insert(i);
    }

    vector<char> foo(sequence.size(), 0);

    for (vector<int>::size_type i {0}; i < sequence.size() - 1; ++i)
    {
        jolly_jumper_contents.erase(abs(sequence[i] - sequence[i + 1]));
    }

    return jolly_jumper_contents.empty();
}

int main()
{
    use_io_optimizations();

    string line;
    getline(cin, line);

    while (!line.empty())
    {
        istringstream line_input {line};

        unsigned int sequence_length;
        line_input >> sequence_length;

        vector<int> sequence(sequence_length);

        for (unsigned int i {0}; i < sequence_length; ++i)
        {
            line_input >> sequence[i];
        }

        cout << (is_jolly_jumper(sequence) ? "Jolly" : "Not jolly") << '\n';

        getline(cin, line);
    }

    return 0;
}
