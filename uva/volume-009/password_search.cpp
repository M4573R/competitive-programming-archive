#include <iostream>
#include <map>
#include <string>

using namespace std;

inline void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int password_size;

    while (cin >> password_size)
    {
        string message;
        cin >> message;

        map<string, unsigned int> frequencies;

        for (string::size_type i {0}; i < message.size() - password_size; ++i)
        {
            ++frequencies[message.substr(i, password_size)];
        }

        string password {frequencies.begin()->first};

        for (const auto& substring_and_frequency : frequencies)
        {
            string       substring {substring_and_frequency.first};
            unsigned int frequency {substring_and_frequency.second};

            if (frequencies[password] < frequency)
            {
                password = substring;
            }
        }

        cout << password << '\n';
    }

    return 0;
}
