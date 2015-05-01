#include <algorithm>
#include <string>

using namespace std;

class CorruptedMessage
{
public:
    string reconstructMessage(string message, int corrupted)
    {
        char initial_letter {'a'};

        for (char letter {'a'}; letter <= 'z'; ++letter)
        {
            if (message.size() -
                count(message.cbegin(), message.cend(), letter) == corrupted)
            {
                initial_letter = letter;
            }
        }

        return string(message.size(), initial_letter);
    }
};
