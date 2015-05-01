#include <cctype>
#include <string>

using namespace std;

class NamingConvention
{
public:
    string toCamelCase(string variableName)
    {
        string camel_case;

        for (string::size_type i {0}; i < variableName.size(); ++i)
        {
            if (variableName[i] == '_')
            {
                camel_case += toupper(variableName[++i]);
            }
            else
            {
                camel_case += variableName[i];
            }
        }

        return camel_case;
    }
};
