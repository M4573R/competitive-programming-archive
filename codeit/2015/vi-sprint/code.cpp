#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string min_lex(const string& sequence)
{
    string minimum;

    for (unsigned int left = 0, right = sequence.size() - 1; left <= right; )
    {
        if (sequence[left] < sequence[right])
        {
            minimum += sequence[left++];
        }
        else if (sequence[left] > sequence[right])
        {
            minimum += sequence[right--];
        }
        else
        {
            bool equal = true;

            for (unsigned int i = left, j = right; i <= j && equal; ++i, --j)
            {
                if (sequence[i] < sequence[j])
                {
                    minimum += sequence[left++];
                    equal = false;
                }
                else if (sequence[i] > sequence[j])
                {
                    minimum += sequence[right--];
                    equal = false;
                }
            }

            if (equal)
            {
                minimum += sequence[left++];
            }
        }
    }

    return minimum;
}

int main()
{
    freopen("code.in",  "r", stdin);
    freopen("code.out", "w", stdout);

    unsigned int length;
    cin >> length;

    string sequence;
    cin >> sequence;

    cout << min_lex(sequence) << '\n';

    return 0;
}
