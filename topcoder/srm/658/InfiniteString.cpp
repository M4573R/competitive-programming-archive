#include <string>

using namespace std;

class InfiniteString
{
public:
    string equal(string s, string t)
    {
        return s + t == t + s ? "Equal" : "Not equal";
    }
};
