#include <iostream>
#include <map>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int requests;
    cin >> requests;

    map<string, unsigned int> database;

    for (unsigned int i {0}; i < requests; ++i)
    {
        string name;
        cin >> name;

        if (!database.count(name))
        {
            cout << "OK\n";
            database[name] = 1;
        }
        else
        {
            cout << name << database[name] << '\n';
            ++database[name];
        }
    }

    return 0;
}
