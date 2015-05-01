#include <set>
#include <string>
#include <vector>

using namespace std;

class UserName
{
public:
    string newMember(vector<string> existingNames, string newName)
    {
        set<string> names(existingNames.cbegin(), existingNames.cend());

        string suggestion {newName};

        for (int i {1}; names.count(suggestion); ++i)
        {
            suggestion = newName + to_string(i);
        }

        return suggestion;
    }
};
