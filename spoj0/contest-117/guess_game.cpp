#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int lower_limit = 1;
const int upper_limit = 1000;

const int ambiguous = -1;
const int lied      = -2;

set<int> intersect(const set<int>& left, const set<int>& right)
{
    set<int> intersection;

    set_intersection(left.begin(),
                     left.end(),
                     right.begin(),
                     right.end(),
                     inserter(intersection, intersection.begin()));

    return intersection;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test_case = 0; test_case < test_cases; ++test_case)
    {
        unsigned int guesses;
        cin >> guesses;

        set<int> thought_number;

        for (unsigned int i = 0; i < guesses; ++i)
        {
            int guess;
            int answer;

            cin >> guess >> answer;

            set<int> possible;

            if (guess - answer >= lower_limit)
            {
                possible.insert(guess - answer);
            }

            if (guess + answer <= upper_limit)
            {
                possible.insert(guess + answer);
            }

            if (i == 0)
            {
                thought_number = possible;
            }
            else
            {
                thought_number = intersect(thought_number, possible);
            }
        }

        if (thought_number.size() == 0)
        {
            cout << lied;
        }
        else if (thought_number.size() == 1)
        {
            cout << *thought_number.begin();
        }
        else
        {
            cout << ambiguous;
        }

        cout << '\n';
    }

    return 0;
}
