#include <string>

using namespace std;

class IdentifyingWood
{
public:
    string check(string s, string t)
    {
        string::size_type i = 0;
        string::size_type j = 0;

        while (i < s.length())
        {
            if (s[i] == t[j])
            {
                ++j;
            }

            ++i;
        }

        return j == t.length() ? "Yep, it's wood." : "Nope.";
    }
};
